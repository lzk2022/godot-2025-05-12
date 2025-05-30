/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef CUBEMAP_DOWNSAMPLER_GLSL_GEN_H_RD
#define CUBEMAP_DOWNSAMPLER_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class CubemapDownsamplerShaderRD : public ShaderRD {

public:

	CubemapDownsamplerShaderRD() {

		static const char _compute_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

#define BLOCK_SIZE 8

layout(local_size_x = BLOCK_SIZE, local_size_y = BLOCK_SIZE, local_size_z = 1) in;

layout(set = 0, binding = 0) uniform samplerCube source_cubemap;

layout(rgba16f, set = 1, binding = 0) uniform restrict writeonly imageCube dest_cubemap;

layout(push_constant, std430) uniform Params {
	uint face_size;
	uint face_id; 
}
params;

#define M_PI 3.14159265359

void get_dir_0(out vec3 dir, in float u, in float v) {
	dir[0] = 1.0;
	dir[1] = v;
	dir[2] = -u;
}

void get_dir_1(out vec3 dir, in float u, in float v) {
	dir[0] = -1.0;
	dir[1] = v;
	dir[2] = u;
}

void get_dir_2(out vec3 dir, in float u, in float v) {
	dir[0] = u;
	dir[1] = 1.0;
	dir[2] = -v;
}

void get_dir_3(out vec3 dir, in float u, in float v) {
	dir[0] = u;
	dir[1] = -1.0;
	dir[2] = v;
}

void get_dir_4(out vec3 dir, in float u, in float v) {
	dir[0] = u;
	dir[1] = v;
	dir[2] = 1.0;
}

void get_dir_5(out vec3 dir, in float u, in float v) {
	dir[0] = -u;
	dir[1] = v;
	dir[2] = -1.0;
}

float calcWeight(float u, float v) {
	float val = u * u + v * v + 1.0;
	return val * sqrt(val);
}

void main() {
	uvec3 id = gl_GlobalInvocationID;
	uint face_size = params.face_size;

	if (id.x < face_size && id.y < face_size) {
		float inv_face_size = 1.0 / float(face_size);

		float u0 = (float(id.x) * 2.0 + 1.0 - 0.75) * inv_face_size - 1.0;
		float u1 = (float(id.x) * 2.0 + 1.0 + 0.75) * inv_face_size - 1.0;

		float v0 = (float(id.y) * 2.0 + 1.0 - 0.75) * -inv_face_size + 1.0;
		float v1 = (float(id.y) * 2.0 + 1.0 + 0.75) * -inv_face_size + 1.0;

		float weights[4];
		weights[0] = calcWeight(u0, v0);
		weights[1] = calcWeight(u1, v0);
		weights[2] = calcWeight(u0, v1);
		weights[3] = calcWeight(u1, v1);

		const float wsum = 0.5 / (weights[0] + weights[1] + weights[2] + weights[3]);
		for (int i = 0; i < 4; i++) {
			weights[i] = weights[i] * wsum + .125;
		}

		vec3 dir;
		vec4 color;
		switch (id.z) {
			case 0:
				get_dir_0(dir, u0, v0);
				color = textureLod(source_cubemap, normalize(dir), 0.0) * weights[0];

				get_dir_0(dir, u1, v0);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[1];

				get_dir_0(dir, u0, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[2];

				get_dir_0(dir, u1, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[3];
				break;
			case 1:
				get_dir_1(dir, u0, v0);
				color = textureLod(source_cubemap, normalize(dir), 0.0) * weights[0];

				get_dir_1(dir, u1, v0);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[1];

				get_dir_1(dir, u0, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[2];

				get_dir_1(dir, u1, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[3];
				break;
			case 2:
				get_dir_2(dir, u0, v0);
				color = textureLod(source_cubemap, normalize(dir), 0.0) * weights[0];

				get_dir_2(dir, u1, v0);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[1];

				get_dir_2(dir, u0, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[2];

				get_dir_2(dir, u1, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[3];
				break;
			case 3:
				get_dir_3(dir, u0, v0);
				color = textureLod(source_cubemap, normalize(dir), 0.0) * weights[0];

				get_dir_3(dir, u1, v0);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[1];

				get_dir_3(dir, u0, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[2];

				get_dir_3(dir, u1, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[3];
				break;
			case 4:
				get_dir_4(dir, u0, v0);
				color = textureLod(source_cubemap, normalize(dir), 0.0) * weights[0];

				get_dir_4(dir, u1, v0);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[1];

				get_dir_4(dir, u0, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[2];

				get_dir_4(dir, u1, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[3];
				break;
			default:
				get_dir_5(dir, u0, v0);
				color = textureLod(source_cubemap, normalize(dir), 0.0) * weights[0];

				get_dir_5(dir, u1, v0);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[1];

				get_dir_5(dir, u0, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[2];

				get_dir_5(dir, u1, v1);
				color += textureLod(source_cubemap, normalize(dir), 0.0) * weights[3];
				break;
		}
		imageStore(dest_cubemap, ivec3(id), color);
	}
}
)<!>"
		};
		setup(nullptr, nullptr, _compute_code, "CubemapDownsamplerShaderRD");
	}
};

#endif
