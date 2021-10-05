//A simple fragment shader
#version 410

in vec4 fColor;
in vec3 fNormal;

uniform vec3 lightDirection;

out vec4 FragColor;

void main() {
	vec3 surfaceNormal = normalize(fNormal);
	vec3 lightNormal = normalize(lightDirection);

	vec4 lightColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	lightNormal = normalize(vec3(-1.0f, -1.0f, -1.0f));

	//color = ambientcolor + diffuseColor + specularColor
	//diffuseColor = surfaceColor * (LightNormal dot surfaceNormal) * lightColor
	float lambertTerm = dot(surfaceNormal, -lightNormal);
	lambertTerm = max(0, min(1, lambertTerm));
	vec4 diffuseColor = fColor * lightColor *lambertTerm;

	FragColor = diffuseColor;
}