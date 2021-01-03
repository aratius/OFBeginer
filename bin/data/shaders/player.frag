uniform sampler2DRect tex0;
uniform sampler2DRect tex1;
uniform float u_noiseAmount;
uniform float u_color_value;

vec2 charaSize = vec2(921., 1035.);

void main() {

  vec2 pos = gl_TexCoord[0].st;
  // pos.x /= charaSize.x;
  // pos.y /= charaSize.y;

  vec4 noise = texture2DRect(tex1, pos);

  pos.x += (noise.r - 0.5)*100. * u_noiseAmount;
  pos.y += (noise.r - 0.5)*100. * u_noiseAmount;

  vec4 color = texture2DRect(tex0, pos);

  //白のところはそのまんま
  if(!(color.r==1. && color.g==1. && color.b==1.)) {
    if(!(pos.y < 921. * (1.-u_color_value))) {
      color.r = u_color_value;
    }
    
  }

  gl_FragColor = color;
}