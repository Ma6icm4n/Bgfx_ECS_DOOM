static const uint8_t fs_particle_glsl[389] =
{
	0x46, 0x53, 0x48, 0x0b, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor.......
	0x00, 0x00, 0x00, 0x5d, 0x01, 0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, // ...]...varying v
	0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x76, 0x61, // ec4 v_color0;.va
	0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, // rying vec4 v_tex
	0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, // coord0;.uniform 
	0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, // sampler2D s_texC
	0x6f, 0x6c, 0x6f, 0x72, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, // olor;.void main 
	0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x72, 0x67, 0x62, 0x61, // ().{.  vec4 rgba
	0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, // _1;.  vec4 tmpva
	0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x20, // r_2;.  tmpvar_2 
	0x3d, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x20, 0x28, 0x73, 0x5f, 0x74, // = texture2D (s_t
	0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, // exColor, v_texco
	0x6f, 0x72, 0x64, 0x30, 0x2e, 0x78, 0x79, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x72, 0x67, 0x62, 0x61, // ord0.xy);.  rgba
	0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, // _1.xyz = ((tmpva
	0x72, 0x5f, 0x32, 0x2e, 0x78, 0x78, 0x78, 0x20, 0x2a, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // r_2.xxx * v_colo
	0x72, 0x30, 0x2e, 0x78, 0x79, 0x7a, 0x29, 0x20, 0x2a, 0x20, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, // r0.xyz) * (tmpva
	0x72, 0x5f, 0x32, 0x2e, 0x78, 0x20, 0x2a, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, // r_2.x * v_color0
	0x2e, 0x77, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x72, 0x67, 0x62, 0x61, 0x5f, 0x31, 0x2e, 0x77, // .w));.  rgba_1.w
	0x20, 0x3d, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x20, //  = ((tmpvar_2.x 
	0x2a, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x77, 0x29, 0x20, 0x2a, 0x20, // * v_color0.w) * 
	0x28, 0x31, 0x2e, 0x30, 0x20, 0x2d, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, // (1.0 - v_texcoor
	0x64, 0x30, 0x2e, 0x7a, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, // d0.z));.  gl_Fra
	0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x72, 0x67, 0x62, 0x61, 0x5f, 0x31, 0x3b, // gColor = rgba_1;
	0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                                   // .}...
};
static const uint8_t fs_particle_essl[411] =
{
	0x46, 0x53, 0x48, 0x0b, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor.......
	0x00, 0x00, 0x00, 0x73, 0x01, 0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, // ...s...varying h
	0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // ighp vec4 v_colo
	0x72, 0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, // r0;.varying high
	0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, // p vec4 v_texcoor
	0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, // d0;.uniform samp
	0x6c, 0x65, 0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, // ler2D s_texColor
	0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, // ;.void main ().{
	0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x72, 0x67, 0x62, // .  lowp vec4 rgb
	0x61, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, // a_1;.  lowp vec4
	0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, //  tmpvar_2;.  tmp
	0x76, 0x61, 0x72, 0x5f, 0x32, 0x20, 0x3d, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, // var_2 = texture2
	0x44, 0x20, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, 0x76, // D (s_texColor, v
	0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x78, 0x79, 0x29, 0x3b, 0x0a, // _texcoord0.xy);.
	0x20, 0x20, 0x72, 0x67, 0x62, 0x61, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x28, //   rgba_1.xyz = (
	0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x78, 0x78, 0x20, 0x2a, 0x20, // (tmpvar_2.xxx * 
	0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x78, 0x79, 0x7a, 0x29, 0x20, 0x2a, 0x20, // v_color0.xyz) * 
	0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x20, 0x2a, 0x20, 0x76, 0x5f, // (tmpvar_2.x * v_
	0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x77, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x72, 0x67, // color0.w));.  rg
	0x62, 0x61, 0x5f, 0x31, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, // ba_1.w = ((tmpva
	0x72, 0x5f, 0x32, 0x2e, 0x78, 0x20, 0x2a, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, // r_2.x * v_color0
	0x2e, 0x77, 0x29, 0x20, 0x2a, 0x20, 0x28, 0x31, 0x2e, 0x30, 0x20, 0x2d, 0x20, 0x76, 0x5f, 0x74, // .w) * (1.0 - v_t
	0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x7a, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, // excoord0.z));.  
	0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x72, // gl_FragColor = r
	0x67, 0x62, 0x61, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                               // gba_1;.}...
};
static const uint8_t fs_particle_spv[1303] =
{
	0x46, 0x53, 0x48, 0x0b, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, // _texColor0......
	0x02, 0x1a, 0x00, 0xec, 0x04, 0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x0a, // .........#......
	0x00, 0x08, 0x00, 0xd5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00, 0x01, // ................
	0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, // ...........GLSL.
	0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, // std.450.........
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x09, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, // ................
	0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x6a, 0x00, 0x00, 0x00, 0x6d, // ...main....j...m
	0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x10, 0x00, 0x03, 0x00, 0x04, // ...p...}........
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0xf4, // ................
	0x01, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, // ...........main.
	0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00, 0x23, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, // .......#...s_tex
	0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x05, // ColorSampler....
	0x00, 0x07, 0x00, 0x26, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, // ...&...s_texColo
	0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00, 0x6a, // rTexture.......j
	0x00, 0x00, 0x00, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6f, 0x72, 0x64, 0x00, // ...gl_FragCoord.
	0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x76, 0x5f, 0x63, 0x6f, 0x6c, // .......m...v_col
	0x6f, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x70, 0x00, 0x00, 0x00, 0x76, // or0........p...v
	0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x00, 0x05, 0x00, 0x06, 0x00, 0x7d, // _texcoord0.....}
	0x00, 0x00, 0x00, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, // ...bgfx_FragData
	0x30, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, // 0..G...#..."....
	0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x12, // ...G...#...!....
	0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, // ...G...&..."....
	0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x02, // ...G...&...!....
	0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x6a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0f, // ...G...j........
	0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, // ...G...m........
	0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x70, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, // ...G...p........
	0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, // ...G...}........
	0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x03, // ...........!....
	0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x02, 0x00, 0x06, 0x00, 0x00, 0x00, 0x16, // ................
	0x00, 0x03, 0x00, 0x07, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x19, 0x00, 0x09, 0x00, 0x08, // ....... ........
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, // ................
	0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x17, // ................
	0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, // ............... 
	0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x3b, // ..."...........;
	0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, // ..."...#....... 
	0x00, 0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x3b, // ...%...........;
	0x00, 0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, // ...%...&........
	0x00, 0x03, 0x00, 0x32, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x4b, // ...2...........K
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x07, // ...........+....
	0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x20, 0x00, 0x04, 0x00, 0x69, // ...`......? ...i
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x69, // ...........;...i
	0x00, 0x00, 0x00, 0x6a, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x69, // ...j.......;...i
	0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x69, // ...m.......;...i
	0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x7c, // ...p....... ...|
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x7c, // ...........;...|
	0x00, 0x00, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x03, 0x00, 0x0d, // ...}............
	0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, // .......6........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x05, // ................
	0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x23, // ...=.......$...#
	0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x26, // ...=.......'...&
	0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x6d, // ...=.......n...m
	0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x70, // ...=.......q...p
	0x00, 0x00, 0x00, 0x4f, 0x00, 0x07, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x00, 0x71, // ...O...........q
	0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x56, // ...q...........V
	0x00, 0x05, 0x00, 0x32, 0x00, 0x00, 0x00, 0xc5, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x24, // ...2.......'...$
	0x00, 0x00, 0x00, 0x57, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xc5, // ...W............
	0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x08, 0x00, 0x4b, 0x00, 0x00, 0x00, 0xa1, // .......O...K....
	0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x08, 0x00, 0x4b, 0x00, 0x00, 0x00, 0xa3, // .......O...K....
	0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, // ...n...n........
	0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x4b, 0x00, 0x00, 0x00, 0xa4, // ...........K....
	0x00, 0x00, 0x00, 0xa1, 0x00, 0x00, 0x00, 0xa3, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, // ...........Q....
	0x00, 0x00, 0x00, 0xa6, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8e, // ................
	0x00, 0x05, 0x00, 0x4b, 0x00, 0x00, 0x00, 0xa7, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00, 0xa6, // ...K............
	0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xa9, 0x00, 0x00, 0x00, 0x6e, // ...Q...........n
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x8e, 0x00, 0x05, 0x00, 0x4b, 0x00, 0x00, 0x00, 0xaa, // ...........K....
	0x00, 0x00, 0x00, 0xa7, 0x00, 0x00, 0x00, 0xa9, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x09, 0x00, 0x0d, // ...........O....
	0x00, 0x00, 0x00, 0xac, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xaa, 0x00, 0x00, 0x00, 0x04, // ................
	0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, // ...............Q
	0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x6e, // ...Q...........n
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb1, // ................
	0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, // ...........Q....
	0x00, 0x00, 0x00, 0xb3, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x83, // .......q........
	0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb4, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0xb3, // ...........`....
	0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, 0x00, 0xb1, // ................
	0x00, 0x00, 0x00, 0xb4, 0x00, 0x00, 0x00, 0x52, 0x00, 0x06, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xd2, // .......R........
	0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, 0x00, 0xac, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x3e, // ...............>
	0x00, 0x03, 0x00, 0x7d, 0x00, 0x00, 0x00, 0xd2, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, // ...}...........8
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,                                                       // .......
};
static const uint8_t fs_particle_dx9[336] =
{
	0x46, 0x53, 0x48, 0x0b, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor0......
	0x00, 0x00, 0x00, 0x28, 0x01, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0xff, 0x20, 0x00, 0x43, // ...(......... .C
	0x54, 0x41, 0x42, 0x1c, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x01, // TAB....S........
	0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x30, // ...........L...0
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, // ...........<....
	0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0xab, 0x04, // ...s_texColor...
	0x00, 0x0c, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, // ...............p
	0x73, 0x5f, 0x33, 0x5f, 0x30, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x20, // s_3_0.Microsoft 
	0x28, 0x52, 0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, // (R) HLSL Shader 
	0x43, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x31, 0x30, 0x2e, 0x31, 0x00, 0xab, 0x51, // Compiler 10.1..Q
	0x00, 0x00, 0x05, 0x00, 0x00, 0x0f, 0xa0, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, // ..........?.....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x02, 0x0a, 0x00, 0x00, 0x80, 0x00, // ................
	0x00, 0x0f, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x80, 0x01, 0x00, 0x07, 0x90, 0x1f, // ................
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x90, 0x00, 0x08, 0x0f, 0xa0, 0x42, 0x00, 0x00, 0x03, 0x00, // ...........B....
	0x00, 0x0f, 0x80, 0x01, 0x00, 0xe4, 0x90, 0x00, 0x08, 0xe4, 0xa0, 0x05, 0x00, 0x00, 0x03, 0x00, // ................
	0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x05, 0x00, 0x00, 0x03, 0x00, // ................
	0x00, 0x0f, 0x80, 0x00, 0x00, 0x54, 0x80, 0x00, 0x00, 0x93, 0x90, 0x05, 0x00, 0x00, 0x03, 0x00, // .....T..........
	0x08, 0x07, 0x80, 0x00, 0x00, 0xf9, 0x80, 0x00, 0x00, 0xff, 0x90, 0x02, 0x00, 0x00, 0x03, 0x00, // ................
	0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0xa0, 0x01, 0x00, 0xaa, 0x91, 0x05, 0x00, 0x00, 0x03, 0x00, // ................
	0x08, 0x08, 0x80, 0x00, 0x00, 0x55, 0x80, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, // .....U..........
};
static const uint8_t fs_particle_dx11[548] =
{
	0x46, 0x53, 0x48, 0x0b, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor0......
	0x00, 0x00, 0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, // ....s_texColor0.
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x01, 0x00, 0x00, 0x44, 0x58, 0x42, 0x43, // ............DXBC
	0xdd, 0x04, 0xf1, 0x4a, 0xaa, 0xb0, 0xdf, 0xe0, 0xf5, 0x18, 0x2f, 0x3b, 0x6e, 0xa9, 0x0e, 0x0a, // ...J....../;n...
	0x01, 0x00, 0x00, 0x00, 0xe4, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, // ............,...
	0xa0, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x6c, 0x00, 0x00, 0x00, // ........ISGNl...
	0x03, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........P.......
	0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, // ................
	0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, // ................
	0x01, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........b.......
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0f, 0x07, 0x00, 0x00, // ................
	0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x43, 0x4f, 0x4c, 0x4f, // SV_POSITION.COLO
	0x52, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0x4f, 0x53, 0x47, 0x4e, // R.TEXCOORD..OSGN
	0x2c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, // ,........... ...
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x0f, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x54, 0x41, 0x52, 0x47, 0x45, 0x54, 0x00, 0xab, 0xab, // ....SV_TARGET...
	0x53, 0x48, 0x44, 0x52, 0x08, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, // SHDR....@...B...
	0x5a, 0x00, 0x00, 0x03, 0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x18, 0x00, 0x04, // Z....`......X...
	0x00, 0x70, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, // .p......UU..b...
	0xf2, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0x72, 0x10, 0x10, 0x00, // ........b...r...
	0x02, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // ....e.... ......
	0x68, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x09, 0xf2, 0x00, 0x10, 0x00, // h.......E.......
	0x00, 0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x46, 0x7e, 0x10, 0x00, // ....F.......F~..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, // .....`......8...
	0x22, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // "...............
	0x0a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0xf2, 0x00, 0x10, 0x00, // ........8.......
	0x00, 0x00, 0x00, 0x00, 0x46, 0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x19, 0x10, 0x00, // ....F.......6...
	0x01, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0x72, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // ....8...r ......
	0x96, 0x07, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf6, 0x1f, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x08, 0x22, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x10, 0x10, 0x80, // ....".......*...
	0x41, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, // A........@.....?
	0x38, 0x00, 0x00, 0x07, 0x82, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x10, 0x00, // 8.... ..........
	0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, // ............>...
	0x00, 0x00, 0x00, 0x00,                                                                         // ....
};
static const uint8_t fs_particle_mtl[856] =
{
	0x46, 0x53, 0x48, 0x0b, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x11, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, // _texColorSampler
	0x11, 0x01, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x73, 0x5f, 0x74, 0x65, 0x78, // ...........s_tex
	0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x11, 0x01, 0xff, 0xff, // ColorTexture....
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, // .......s_texColo
	0x72, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf5, 0x02, 0x00, 0x00, 0x23, // r..............#
	0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, 0x73, // include <metal_s
	0x74, 0x64, 0x6c, 0x69, 0x62, 0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, // tdlib>.#include 
	0x3c, 0x73, 0x69, 0x6d, 0x64, 0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, 0x0a, 0x0a, 0x75, // <simd/simd.h>..u
	0x73, 0x69, 0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, 0x65, 0x20, 0x6d, // sing namespace m
	0x65, 0x74, 0x61, 0x6c, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, // etal;..struct xl
	0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x0a, 0x7b, 0x0a, // atMtlMain_out.{.
	0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x62, 0x67, 0x66, 0x78, 0x5f, //     float4 bgfx_
	0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x20, 0x5b, 0x5b, 0x63, 0x6f, 0x6c, 0x6f, // FragData0 [[colo
	0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, // r(0)]];.};..stru
	0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, // ct xlatMtlMain_i
	0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x76, // n.{.    float4 v
	0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, // _color0 [[user(l
	0x6f, 0x63, 0x6e, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, // ocn0)]];.    flo
	0x61, 0x74, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, // at4 v_texcoord0 
	0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x31, 0x29, 0x5d, 0x5d, 0x3b, // [[user(locn1)]];
	0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x78, 0x6c, // .};..fragment xl
	0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x78, 0x6c, // atMtlMain_out xl
	0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x28, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, // atMtlMain(xlatMt
	0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e, 0x20, 0x69, 0x6e, 0x20, 0x5b, 0x5b, 0x73, 0x74, // lMain_in in [[st
	0x61, 0x67, 0x65, 0x5f, 0x69, 0x6e, 0x5d, 0x5d, 0x2c, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, // age_in]], textur
	0x65, 0x32, 0x64, 0x3c, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x3e, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, // e2d<float> s_tex
	0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x5b, 0x5b, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x28, // Color [[texture(
	0x30, 0x29, 0x5d, 0x5d, 0x2c, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, 0x73, 0x5f, // 0)]], sampler s_
	0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, // texColorSampler 
	0x5b, 0x5b, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x29, 0x0a, // [[sampler(0)]]).
	0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, // {.    xlatMtlMai
	0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d, 0x20, 0x7b, 0x7d, 0x3b, 0x0a, // n_out out = {};.
	0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x5f, 0x31, 0x39, 0x36, 0x20, //     float4 _196 
	0x3d, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2e, 0x73, 0x61, 0x6d, // = s_texColor.sam
	0x70, 0x6c, 0x65, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, // ple(s_texColorSa
	0x6d, 0x70, 0x6c, 0x65, 0x72, 0x2c, 0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, // mpler, in.v_texc
	0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x78, 0x79, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, // oord0.xy);.    f
	0x6c, 0x6f, 0x61, 0x74, 0x33, 0x20, 0x5f, 0x31, 0x36, 0x37, 0x20, 0x3d, 0x20, 0x28, 0x28, 0x5f, // loat3 _167 = ((_
	0x31, 0x39, 0x36, 0x2e, 0x78, 0x78, 0x78, 0x20, 0x2a, 0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, // 196.xxx * in.v_c
	0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2e, 0x78, 0x79, 0x7a, 0x29, 0x20, 0x2a, 0x20, 0x5f, 0x31, 0x39, // olor0.xyz) * _19
	0x36, 0x2e, 0x78, 0x29, 0x20, 0x2a, 0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // 6.x) * in.v_colo
	0x72, 0x30, 0x2e, 0x77, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, // r0.w;.    float4
	0x20, 0x5f, 0x32, 0x30, 0x37, 0x20, 0x3d, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x28, 0x5f, //  _207 = float4(_
	0x31, 0x36, 0x37, 0x2e, 0x78, 0x2c, 0x20, 0x5f, 0x31, 0x36, 0x37, 0x2e, 0x79, 0x2c, 0x20, 0x5f, // 167.x, _167.y, _
	0x31, 0x36, 0x37, 0x2e, 0x7a, 0x2c, 0x20, 0x5f, 0x31, 0x39, 0x36, 0x2e, 0x78, 0x29, 0x3b, 0x0a, // 167.z, _196.x);.
	0x20, 0x20, 0x20, 0x20, 0x5f, 0x32, 0x30, 0x37, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x28, 0x5f, 0x31, //     _207.w = (_1
	0x39, 0x36, 0x2e, 0x78, 0x20, 0x2a, 0x20, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // 96.x * in.v_colo
	0x72, 0x30, 0x2e, 0x77, 0x29, 0x20, 0x2a, 0x20, 0x28, 0x31, 0x2e, 0x30, 0x20, 0x2d, 0x20, 0x69, // r0.w) * (1.0 - i
	0x6e, 0x2e, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x7a, 0x29, // n.v_texcoord0.z)
	0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, // ;.    out.bgfx_F
	0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x20, 0x3d, 0x20, 0x5f, 0x32, 0x30, 0x37, 0x3b, // ragData0 = _207;
	0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x3b, // .    return out;
	0x0a, 0x7d, 0x0a, 0x0a, 0x00, 0x00, 0x20, 0x00,                                                 // .}.... .
};
extern const uint8_t* fs_particle_pssl;
extern const uint32_t fs_particle_pssl_size;
