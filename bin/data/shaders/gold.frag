uniform sampler2DRect tex0;

void main() {

  vec2 pos = gl_TexCoord[0].st;

  // vec4 color = vec4(1.0);
  vec4 color = texture2DRect(tex0, pos);

//gold
  color.r = 255./255.;
  color.g = 215./255.;
  color.b = 0.;
  
  gl_FragColor = color;
}