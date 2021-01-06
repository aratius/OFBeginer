uniform sampler2DRect tex0;
uniform float u_alpha;

void main() {

  vec2 pos = gl_TexCoord[0].st;

  // vec4 color = vec4(1.0);
  vec4 color = texture2DRect(tex0, pos);

if(color.a != 0.) {
  if(color.r != 1.) {
    color.rgb = vec3(1. * u_alpha);
  }
  if(color.r != 1. * u_alpha) {
    color.a = 0.5;
  }
}


  
  gl_FragColor = color;
}