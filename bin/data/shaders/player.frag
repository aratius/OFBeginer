uniform sampler2DRect tex0;

void main() {

  vec2 pos = gl_TexCoord[0].st;

  vec4 color = texture2DRect(tex0, pos);
  // if(color.a == 0) {
    color.r = 1.0;
    // color.g = 0.5;
    // color.b = 0.5;
  // }

  gl_FragColor = color;
}