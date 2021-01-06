uniform sampler2DRect tex0;
uniform vec3 u_color_val;
uniform float u_alpha;

void main() {

  vec2 pos = gl_TexCoord[0].st;

  // vec4 color = vec4(1.0);
  vec4 color = texture2DRect(tex0, pos);

//gold
  color.rgba = vec4(u_color_val.rgb, u_alpha);
  
  gl_FragColor = color;
}