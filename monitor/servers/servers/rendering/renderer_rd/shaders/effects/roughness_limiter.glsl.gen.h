/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef ROUGHNESS_LIMITER_GLSL_GEN_H_RD
#define ROUGHNESS_LIMITER_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class RoughnessLimiterShaderRD : public ShaderRD {

public:

	RoughnessLimiterShaderRD() {

		static const char _compute_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

layout(local_size_x = 8, local_size_y = 8, local_size_z = 1) in;

layout(set = 0, binding = 0) uniform sampler2D source_normal;
layout(r8, set = 1, binding = 0) uniform restrict writeonly image2D dest_roughness;

layout(push_constant, std430) uniform Params {
	ivec2 screen_size;
	float curve;
	uint pad;
}
params;

#define HALF_PI 1.5707963267948966

void main() {
	
	ivec2 pos = ivec2(gl_GlobalInvocationID.xy);
	if (any(greaterThan(pos, params.screen_size))) { 
		return;
	}

	vec3 normal_accum = vec3(0.0);
	float accum = 0.0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			normal_accum += normalize(texelFetch(source_normal, pos + ivec2(i, j), 0).xyz * 2.0 - 1.0);
			accum += 1.0;
		}
	}

	normal_accum /= accum;

	float r = length(normal_accum);

	float limit;

	if (r < 1.0) {
		float threshold = 0.4;

		/*
		

		float r2 = r * r;
		float kappa = (3.0f * r - r * r2) / (1.0f - r2);
		float variance = 0.25f / kappa;
		limit = sqrt(min(2.0f * variance, threshold * threshold));
		*/
		/*
		

		float width = acos(max(0.0,r)); 
		float roughness = pow(width,1.7)*0.854492; 
		limit = min(sqrt(roughness), threshold); 
		*/

		limit = min(sqrt(pow(acos(max(0.0, r)) / HALF_PI, params.curve)), threshold); 

		
	} else {
		limit = 0.0;
	}

	imageStore(dest_roughness, pos, vec4(limit));
}
)<!>"
		};
		setup(nullptr, nullptr, _compute_code, "RoughnessLimiterShaderRD");
	}
};

#endif
