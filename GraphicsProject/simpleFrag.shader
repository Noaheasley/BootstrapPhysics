//A simple fragment shader
#version 410

in vec4 fPosition;
in vec4 fColor;
in vec3 fNormal;

uniform vec3 lightDirection;
uniform vec4 lightAmbient;
uniform vec4 lightDiffuse;
uniform vec4 lightSpecular;
uniform float specularPower;

uniform vec4 cameraPosition;

out vec4 FragColor;

void main() {
	vec3 surfaceNormal = normalize(fNormal);
	vec3 lightNormal = normalize(lightDirection);

	//calculate ambient color
	vec4 ambientColor = fColor * lightAmbient;

	//calculate diffuse color
	float lambertTerm = dot(surfaceNormal, -lightNormal);
	lambertTerm = max(0, min(1, lambertTerm));
	vec4 diffuseColor = fColor * lightDiffuse *lambertTerm;

	//calculate specular color
	vec3 surfaceToView = normalize(cameraPosition.xyz - fPosition.xyz);
	vec3 reflectionNormal = reflect(lightNormal, surfaceNormal);
	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0, specularTerm);
	specularTerm = pow(specularTerm, specularPower);
	vec4 specularColor = fColor * lightSpecular * specularTerm;
	
	FragColor = ambientColor + diffuseColor + specularColor;
}