uniform float u_col_r;
uniform sampler2DRect u_playerTex;

void main() {

  vec2 cord = gl_FragCoord;

  vec4 color = texture(u_playerTex,cord);

  gl_FragColor = color;
}