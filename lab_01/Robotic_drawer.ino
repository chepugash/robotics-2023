// C++ code
//
#include <Servo.h>

const int SERVO_PIN1 = 3;
const int SERVO_PIN2 = 4;
const int SERVO_PIN3 = 5;

Servo servos[3];

String input;

int index;
float first_float, second_float;

float current_x, current_y;

float l1 = 73;
float l2 = 65;

int servo1_offset;

void get_coordinates(float &x, float &y) {
  float first_angle = servos[1].read()*3.14/180;
  float second_angle = servos[2].read()*3.14/180;
  
  x = cos(first_angle)*l1-cos(first_angle+second_angle)*l2;
  y = sin(first_angle)*l1-sin(first_angle+second_angle)*l2;
  
}

void up() {
  for (int i = servo1_offset; i <= 45; i++) {
    servos[0].write(i);
    delay(20);
  }
}

void down() {
  for (int i = servo1_offset; i <= 45; i++) {
    servos[0].write(45 - i);
    delay(20);
  }
}

// void movePenTo(int x, int y) {
//   int l1 = 75;
//   int l2 = 65;
//   double angle1; 
//   angle1 = 180 / M_PI * (acos((square(l1) + square(x) + square(y) - square(l2))/(2 * l1 * sqrt(square(x) + square(y)))) + acos(x/sqrt(square(x) + square(y))));
//   double angle2; 
//   angle2 = 180 / M_PI * (acos((square(l1) + square(l2) - square(x) - square(y))/(2 * l1 * l2)));
//   servo.write((int)angle1);
//   delay(100);
//   servos[1].write((int)angle2);
//   delay(100);
// }

void drawLine(float x1, float y1, float x2, float y2) {
  if (x1 == x2) {
    float s = 0.1;
    if(y1 > y2) {
      s = -0.1;
    }
    for (float c = y1; c == y2; c += s) {
      movePenTo(x1, c);
    }
  } else {
      float s = 0.1;
    if(x1 > x2) {
      s = -0.1;
    }
    for (float c = x1; c == x2; c += s) {
      movePenTo(c, y1);
    }
  }
}

void movePenTo(float x, float y) {
  delay(50);
  
  float hypotenuse = sqrt(pow(x, 2)+pow(y, 2));
  float first_angle = atan(y/x)+acos((pow(l1, 2)+pow(hypotenuse, 2)-pow(l2, 2))/(2*l1*hypotenuse));
  float second_angle = acos((pow(l1, 2)+pow(l2, 2)-pow(hypotenuse, 2))/(2*l1*l2));
  
  servos[1].write(first_angle*180/3.14);
  servos[2].write(second_angle*180/3.14);
  
  delay(50);
  
  get_coordinates(current_x, current_y);
  Serial.println(current_x);
  Serial.println(current_y);
}

void setup()
{
  Serial.begin(9600);
  
  servos[0].attach(SERVO_PIN1);
  servos[1].attach(SERVO_PIN2);
  servos[2].attach(SERVO_PIN3);
  servo1_offset = 0;
  servos[0].write(servo1_offset);
}



void loop()
{
  up();
  down();
  // if (Serial.available() > 0) {
  //   input = Serial.readString();
  //   index = input.indexOf(' ');

  //   first_float = input.substring(0, index).toFloat();
  //   second_float = input.substring(index).toFloat();

  //   Serial.println(first_float);
  //   Serial.println(second_float);
  //   get_coordinates(current_x, current_y);
    // drawLine(current_x, current_y, first_float, second_float);
    // for (float i = 5.0; i <= 7.0; i = i + 0.1) {
    // movePenTo(5, i);
  // }

  // for (float i = 5.0; i <= 7.0; i = i + 0.1) {
  //   movePenTo(i, 7);
  // }

  // for (float i = 7.0; i >= 5.0; i = i - 0.1) {
  //   movePenTo(7, i);
  // }

  // for (float i = 7.0; i >= 5.0; i = i - 0.1) {
  //   movePenTo(i, 5);
  // }
  // }
  movePenTo(24.424, 43.865);
movePenTo(25.607, 42.597);
movePenTo(26.35, 41.9);
movePenTo(27.113, 41.23);
movePenTo(28.736, 39.965);
movePenTo(30.381, 38.733);
movePenTo(32.012, 37.623);
movePenTo(33.658, 36.543);
movePenTo(34.816, 35.829);
movePenTo(36.01, 35.139);
movePenTo(36.907, 34.742);
movePenTo(37.811, 34.393);
movePenTo(40.021, 33.694);
movePenTo(42.248, 33.03);
movePenTo(43.873, 32.684);
movePenTo(47.244, 31.747);
movePenTo(50.593, 30.762);
movePenTo(53.145, 29.746);
movePenTo(55.791, 28.778);
movePenTo(58.237, 28.552);
movePenTo(60.666, 28.485);
movePenTo(61.655, 28.548);
movePenTo(62.698, 28.757);
movePenTo(63.709, 29.529);
movePenTo(64.583, 30.388);
movePenTo(66.902, 33.8);
movePenTo(68.045, 34.81);
movePenTo(69.009, 35.924);
movePenTo(70.697, 37.438);
movePenTo(72.429, 39.042);
movePenTo(73.478, 40.697);
movePenTo(74.289, 41.133);
movePenTo(72.252, 44.067);
movePenTo(70.715, 46.199);
movePenTo(69.235, 47.693);
movePenTo(67.408, 49.97);
movePenTo(64.557, 52.936);
movePenTo(61.684, 55.86);
movePenTo(60.574, 56.931);
movePenTo(59.404, 57.97);
movePenTo(57.279, 59.412);
movePenTo(55.117, 60.784);
movePenTo(53.856, 61.441);
movePenTo(52.572, 62.056);
movePenTo(52.017, 62.262);
movePenTo(51.411, 62.424);
movePenTo(50.023, 62.448);
movePenTo(48.688, 62.425);
movePenTo(47.643, 62.384);
movePenTo(46.56, 62.283);
movePenTo(45.323, 61.879);
movePenTo(44.146, 61.427);
movePenTo(42.993, 60.917);
movePenTo(41.852, 60.349);
movePenTo(40.154, 59.226);
movePenTo(38.481, 58.051);
movePenTo(37.803, 57.388);
movePenTo(36.091, 56.137);
movePenTo(34.74, 54.98);
movePenTo(33.427, 53.764);
movePenTo(29.752, 49.309);
movePenTo(25.258, 45.131);
movePenTo(24.942, 44.707);
movePenTo(24.817, 44.504);
movePenTo(23.267, 42.573);
movePenTo(23.664, 44.333);
movePenTo(24.108, 45.055);
movePenTo(22.645, 45.754);
movePenTo(22.656, 44.982);
movePenTo(22.786, 44.636);
movePenTo(23.253, 43.664);
movePenTo(23.271, 43.694);
movePenTo(31.818, 54.962);
movePenTo(30.975, 53.831);
movePenTo(29.683, 52.275);
movePenTo(28.346, 50.746);
movePenTo(23.566, 46.303);
movePenTo(23.029, 46.56);
movePenTo(22.661, 46.56);
movePenTo(22.32, 46.5);
movePenTo(22.053, 46.285);
movePenTo(21.846, 46.026);
movePenTo(21.757, 45.449);
movePenTo(21.766, 44.814);
movePenTo(21.964, 44.285);
movePenTo(22.378, 43.423);
movePenTo(22.39, 43.255);
movePenTo(22.498, 42.975);
movePenTo(22.645, 42.741);
movePenTo(22.983, 42.536);
movePenTo(24.19, 41.185);
movePenTo(25.001, 40.426);
movePenTo(25.846, 39.69);
movePenTo(27.515, 38.38);
movePenTo(29.207, 37.102);
movePenTo(30.871, 35.981);
movePenTo(32.561, 34.881);
movePenTo(34.444, 33.701);
movePenTo(32.946, 32.849);
movePenTo(32.32, 32.443);
movePenTo(31.009, 31.49);
movePenTo(29.737, 30.509);
movePenTo(28.957, 29.773);
movePenTo(28.22, 29.007);
movePenTo(27.75, 28.367);
movePenTo(27.358, 27.738);
movePenTo(27.288, 27.452);
movePenTo(27.277, 27.205);
movePenTo(27.425, 26.872);
movePenTo(27.62, 26.587);
movePenTo(27.925, 26.438);
movePenTo(28.26, 26.351);
movePenTo(28.592, 26.433);
movePenTo(28.91, 26.581);
movePenTo(29.265, 27.044);
movePenTo(29.698, 27.667);
movePenTo(30.311, 28.31);
movePenTo(30.946, 28.916);
movePenTo(32.191, 29.87);
movePenTo(33.444, 30.789);
movePenTo(33.859, 31.067);
movePenTo(34.385, 31.371);
movePenTo(34.85, 31.386);
movePenTo(35.194, 31.56);
movePenTo(35.498, 31.763);
movePenTo(35.618, 31.98);
movePenTo(35.703, 32.246);
movePenTo(35.661, 33.073);
movePenTo(36.989, 32.561);
movePenTo(38.503, 32.069);
movePenTo(40.93, 31.318);
movePenTo(40.782, 30.845);
movePenTo(40.707, 29.51);
movePenTo(40.665, 28.038);
movePenTo(40.078, 25.419);
movePenTo(40.033, 24.69);
movePenTo(40.05, 24.01);
movePenTo(40.15, 23.738);
movePenTo(40.278, 23.526);
movePenTo(40.587, 23.333);
movePenTo(40.927, 23.191);
movePenTo(41.179, 23.206);
movePenTo(41.432, 23.274);
movePenTo(41.715, 23.509);
movePenTo(41.924, 23.762);
movePenTo(41.989, 24.282);
movePenTo(42.041, 25.009);
movePenTo(42.363, 26.406);
movePenTo(42.639, 27.725);
movePenTo(42.68, 28.895);
movePenTo(42.645, 30.953);
movePenTo(48.461, 29.33);
movePenTo(48.847, 27.715);
movePenTo(49.218, 26.389);
movePenTo(49.522, 24.937);
movePenTo(49.8, 23.459);
movePenTo(49.829, 22.458);
movePenTo(49.99, 22.115);
movePenTo(50.188, 21.82);
movePenTo(50.405, 21.701);
movePenTo(50.669, 21.616);
movePenTo(50.954, 21.636);
movePenTo(51.212, 21.701);
movePenTo(51.485, 21.931);
movePenTo(51.693, 22.189);
movePenTo(51.786, 22.792);
movePenTo(51.801, 23.503);
movePenTo(51.515, 25.174);
movePenTo(51.155, 26.875);
movePenTo(50.706, 28.597);
movePenTo(53.631, 27.45);
movePenTo(55.138, 26.888);
movePenTo(55.875, 26.742);
movePenTo(57.356, 26.574);
movePenTo(57.22, 25.849);
movePenTo(57.296, 25.439);
movePenTo(57.445, 25.051);
movePenTo(59.937, 22.293);
movePenTo(61.496, 19.655);
movePenTo(61.785, 19.501);
movePenTo(62.14, 19.401);
movePenTo(62.398, 19.444);
movePenTo(62.66, 19.537);
movePenTo(62.867, 19.723);
movePenTo(63.028, 19.932);
movePenTo(63.106, 20.287);
movePenTo(63.11, 20.637);
movePenTo(62.451, 21.984);
movePenTo(61.646, 23.349);
movePenTo(60.681, 24.429);
movePenTo(58.697, 26.499);
movePenTo(60.713, 26.485);
movePenTo(62.058, 26.594);
movePenTo(63.286, 26.818);
movePenTo(64.272, 27.469);
movePenTo(65.286, 28.274);
movePenTo(65.895, 28.81);
movePenTo(67.445, 27.238);
movePenTo(69.234, 25.139);
movePenTo(69.516, 24.934);
movePenTo(69.78, 24.797);
movePenTo(70.053, 24.778);
movePenTo(70.327, 24.807);
movePenTo(70.564, 24.94);
movePenTo(70.782, 25.113);
movePenTo(70.917, 25.36);
movePenTo(71.013, 25.627);
movePenTo(71.001, 25.897);
movePenTo(70.938, 26.149);
movePenTo(69.985, 27.356);
movePenTo(68.912, 28.603);
movePenTo(68.192, 29.351);
movePenTo(67.45, 30.065);
movePenTo(66.978, 30.448);
movePenTo(67.803, 31.685);
movePenTo(68.277, 32.35);
movePenTo(68.869, 32.881);
movePenTo(69.417, 33.339);
movePenTo(71.772, 35.859);
movePenTo(72.923, 36.822);
movePenTo(73.977, 37.751);
movePenTo(74.321, 38.237);
movePenTo(75.188, 39.686);
movePenTo(76.412, 37.703);
movePenTo(76.614, 37.478);
movePenTo(76.897, 37.325);
movePenTo(77.139, 37.236);
movePenTo(77.489, 37.281);
movePenTo(77.832, 37.381);
movePenTo(78.017, 37.554);
movePenTo(78.172, 37.769);
movePenTo(78.243, 38.126);
movePenTo(78.235, 38.463);
movePenTo(77.242, 40.212);
movePenTo(76.094, 42.029);
movePenTo(74.217, 44.752);
movePenTo(72.303, 47.412);
movePenTo(70.77, 48.975);
movePenTo(70.029, 49.873);
movePenTo(70.525, 50.217);
movePenTo(70.728, 50.631);
movePenTo(70.981, 51.234);
movePenTo(72.764, 54.13);
movePenTo(74.617, 56.985);
movePenTo(75.449, 57.867);
movePenTo(76.315, 58.685);
movePenTo(77.234, 59.448);
movePenTo(77.382, 59.702);
movePenTo(77.471, 59.946);
movePenTo(77.43, 60.304);
movePenTo(77.331, 60.633);
movePenTo(77.088, 60.862);
movePenTo(76.801, 61.045);
movePenTo(76.457, 61.067);
movePenTo(76.105, 61.023);
movePenTo(75.63, 60.708);
movePenTo(75.101, 60.274);
movePenTo(74.086, 59.326);
movePenTo(73.155, 58.343);
movePenTo(71.135, 55.286);
movePenTo(69.197, 52.162);
movePenTo(68.837, 51.389);
movePenTo(66.388, 53.986);
movePenTo(62.194, 58.17);
movePenTo(63.379, 58.635);
movePenTo(63.657, 58.817);
movePenTo(64.106, 59.747);
movePenTo(64.587, 60.871);
movePenTo(65.38, 62.292);
movePenTo(65.968, 63.736);
movePenTo(66.528, 65.206);
movePenTo(67.009, 66.815);
movePenTo(67.632, 68.372);
movePenTo(67.784, 69.067);
movePenTo(67.875, 69.722);
movePenTo(67.814, 70.013);
movePenTo(67.713, 70.273);
movePenTo(67.523, 70.467);
movePenTo(67.314, 70.617);
movePenTo(66.951, 70.68);
movePenTo(66.612, 70.68);
movePenTo(66.321, 70.509);
movePenTo(66.076, 70.288);
movePenTo(65.921, 69.762);
movePenTo(65.756, 69.036);
movePenTo(65.179, 67.593);
movePenTo(64.685, 65.993);
movePenTo(64.16, 64.594);
movePenTo(63.599, 63.193);
movePenTo(62.858, 61.879);
movePenTo(62.186, 60.388);
movePenTo(62.045, 59.995);
movePenTo(61.949, 59.631);
movePenTo(61.906, 58.477);
movePenTo(60.859, 59.37);
movePenTo(59.307, 60.476);
movePenTo(57.718, 61.548);
movePenTo(56.064, 62.538);
movePenTo(53.838, 63.681);
movePenTo(54.464, 64.477);
movePenTo(54.579, 64.705);
movePenTo(54.638, 67.275);
movePenTo(54.922, 68.696);
movePenTo(54.955, 74.102);
movePenTo(54.953, 79.56);
movePenTo(54.864, 79.963);
movePenTo(54.772, 80.216);
movePenTo(54.511, 80.44);
movePenTo(54.226, 80.607);
movePenTo(53.885, 80.6);
movePenTo(53.476, 80.538);
movePenTo(53.397, 80.498);
movePenTo(53.319, 80.438);
movePenTo(53.126, 80.185);
movePenTo(53.01, 79.954);
movePenTo(52.95, 74.645);
movePenTo(52.953, 69.102);
movePenTo(52.665, 67.601);
movePenTo(52.629, 66.322);
movePenTo(52.637, 65.028);
movePenTo(52.715, 64.307);
movePenTo(50.269, 64.424);
movePenTo(48.504, 64.425);
movePenTo(47.422, 64.372);
movePenTo(46.381, 64.267);
movePenTo(45.294, 63.96);
movePenTo(44.196, 63.586);
movePenTo(43.332, 63.236);
movePenTo(43.058, 63.627);
movePenTo(42.66, 63.459);
movePenTo(42.749, 62.986);
movePenTo(41.622, 62.481);
movePenTo(40.955, 62.15);
movePenTo(39.136, 60.965);
movePenTo(37.365, 59.723);
movePenTo(36.588, 58.976);
movePenTo(34.942, 57.782);
movePenTo(33.156, 56.253);
movePenTo(31.357, 60.415);
movePenTo(29.996, 63.448);
movePenTo(29.354, 64.698);
movePenTo(28.68, 65.932);
movePenTo(28.356, 66.45);
movePenTo(28.014, 66.939);
movePenTo(26.935, 68.15);
movePenTo(25.84, 69.318);
movePenTo(25.639, 69.462);
movePenTo(25.473, 69.545);
movePenTo(25.082, 69.563);
movePenTo(24.694, 69.534);
movePenTo(24.55, 69.457);
movePenTo(24.406, 69.343);
movePenTo(24.248, 69.086);
movePenTo(24.135, 68.822);
movePenTo(24.129, 68.555);
movePenTo(24.175, 68.331);
movePenTo(25.207, 67.11);
movePenTo(26.389, 65.782);
movePenTo(26.975, 64.899);
movePenTo(27.557, 63.838);
movePenTo(28.112, 62.763);
movePenTo(29.061, 60.382);
movePenTo(30.258, 57.781);
movePenTo(31.375, 55.559);
movePenTo(32.819, 53.968);
movePenTo(41.611, 64.124);
movePenTo(41.866, 63.974);
movePenTo(42.151, 63.86);
movePenTo(42.716, 63.83);
movePenTo(43.104, 64.258);
movePenTo(43.228, 64.528);
movePenTo(43.278, 64.75);
movePenTo(42.646, 66.646);
movePenTo(42.343, 69.237);
movePenTo(42.044, 70.606);
movePenTo(41.697, 71.967);
movePenTo(41.075, 73.789);
movePenTo(40.405, 75.565);
movePenTo(39.527, 77.009);
movePenTo(38.965, 78.295);
movePenTo(38.526, 78.899);
movePenTo(38.049, 79.471);
movePenTo(37.77, 79.682);
movePenTo(37.52, 79.822);
movePenTo(37.246, 79.835);
movePenTo(36.905, 79.819);
movePenTo(36.587, 79.534);
movePenTo(36.356, 79.275);
movePenTo(36.292, 78.946);
movePenTo(36.299, 78.626);
movePenTo(36.653, 78.093);
movePenTo(37.164, 77.406);
movePenTo(37.744, 76.14);
movePenTo(38.547, 74.822);
movePenTo(39.169, 73.206);
movePenTo(39.731, 71.595);
movePenTo(40.077, 70.251);
movePenTo(40.376, 68.892);
movePenTo(40.658, 66.384);
movePenTo(40.975, 65.449);
movePenTo(41.247, 64.774);
movePenTo(41.892, 64.217);
movePenTo(49.359, 48.949);
movePenTo(49.359, 48.546);
movePenTo(49.752, 48.438);
movePenTo(49.945, 48.76);
movePenTo(49.937, 48.773);
movePenTo(46.208, 52.97);
movePenTo(46.61, 53.182);
movePenTo(46.992, 53.328);
movePenTo(47.616, 53.483);
movePenTo(48.26, 53.604);
movePenTo(49.023, 53.62);
movePenTo(49.758, 53.605);
movePenTo(50.646, 53.549);
movePenTo(51.568, 53.446);
movePenTo(52.539, 53.13);
movePenTo(53.491, 52.757);
movePenTo(53.943, 52.465);
movePenTo(54.364, 52.142);
movePenTo(54.666, 51.819);
movePenTo(54.954, 51.437);
movePenTo(55.17, 50.808);
movePenTo(55.32, 50.185);
movePenTo(55.341, 49.274);
movePenTo(55.321, 48.398);
movePenTo(55.184, 46.755);
movePenTo(55.083, 45.892);
movePenTo(54.89, 44.993);
movePenTo(53.433, 42.349);
movePenTo(51.896, 39.772);
movePenTo(51.513, 39.345);
movePenTo(51.102, 38.976);
movePenTo(50.332, 38.412);
movePenTo(49.478, 37.891);
movePenTo(48.356, 37.633);
movePenTo(47.259, 37.471);
movePenTo(46.392, 37.452);
movePenTo(45.55, 37.47);
movePenTo(44.695, 37.509);
movePenTo(43.799, 37.615);
movePenTo(42.213, 38.2);
movePenTo(40.66, 38.894);
movePenTo(40.025, 39.446);
movePenTo(39.487, 40.065);
movePenTo(38.892, 41.114);
movePenTo(38.401, 42.241);
movePenTo(38.275, 43.714);
movePenTo(38.204, 46.353);
movePenTo(38.244, 47.643);
movePenTo(38.645, 48.849);
movePenTo(39.131, 49.978);
movePenTo(40.501, 52.52);
movePenTo(41.973, 55.048);
movePenTo(42.556, 55.629);
movePenTo(43.158, 56.123);
movePenTo(43.877, 56.662);
movePenTo(44.646, 57.172);
movePenTo(46.296, 57.945);
movePenTo(48.02, 58.639);
movePenTo(48.898, 58.694);
movePenTo(49.745, 58.642);
movePenTo(53.23, 57.891);
movePenTo(53.536, 57.866);
movePenTo(53.787, 57.876);
movePenTo(54.063, 57.985);
movePenTo(54.302, 58.122);
movePenTo(54.47, 58.348);
movePenTo(54.6, 58.599);
movePenTo(54.62, 58.872);
movePenTo(54.591, 59.138);
movePenTo(54.406, 59.448);
movePenTo(54.185, 59.677);
movePenTo(52.222, 60.193);
movePenTo(50.105, 60.618);
movePenTo(48.975, 60.698);
movePenTo(47.902, 60.649);
movePenTo(45.86, 59.899);
movePenTo(43.823, 59.007);
movePenTo(42.927, 58.437);
movePenTo(42.048, 57.794);
movePenTo(41.165, 57.072);
movePenTo(40.399, 56.32);
movePenTo(38.825, 53.637);
movePenTo(37.333, 50.848);
movePenTo(36.775, 49.546);
movePenTo(36.342, 48.253);
movePenTo(36.246, 46.735);
movePenTo(36.242, 45.144);
movePenTo(36.273, 43.443);
movePenTo(36.413, 41.841);
movePenTo(36.996, 40.441);
movePenTo(37.733, 39.076);
movePenTo(38.481, 38.173);
movePenTo(39.313, 37.397);
movePenTo(41.187, 36.488);
movePenTo(43.148, 35.711);
movePenTo(44.209, 35.551);
movePenTo(45.336, 35.47);
movePenTo(46.324, 35.445);
movePenTo(47.296, 35.469);
movePenTo(48.659, 35.656);
movePenTo(49.948, 35.938);
movePenTo(51.12, 36.591);
movePenTo(52.284, 37.364);
movePenTo(52.856, 37.857);
movePenTo(53.356, 38.394);
movePenTo(55.081, 41.226);
movePenTo(56.678, 44.11);
movePenTo(56.952, 45.201);
movePenTo(57.146, 46.377);
movePenTo(57.241, 47.274);
movePenTo(57.307, 48.181);
movePenTo(57.341, 49.255);
movePenTo(57.323, 50.286);
movePenTo(57.113, 51.234);
movePenTo(56.826, 52.139);
movePenTo(56.381, 52.82);
movePenTo(55.859, 53.472);
movePenTo(55.242, 53.983);
movePenTo(54.582, 54.433);
movePenTo(53.378, 54.937);
movePenTo(52.142, 55.361);
movePenTo(51.07, 55.503);
movePenTo(49.95, 55.591);
movePenTo(49.041, 55.618);
movePenTo(48.164, 55.606);
movePenTo(47.342, 55.461);
movePenTo(46.521, 55.265);
movePenTo(45.769, 54.991);
movePenTo(45.107, 54.67);
movePenTo(44.264, 53.857);
movePenTo(43.468, 52.945);
movePenTo(42.974, 52.113);
movePenTo(42.611, 51.279);
movePenTo(42.539, 49.864);
movePenTo(42.556, 48.367);
movePenTo(42.579, 48.177);
movePenTo(43.287, 47.321);
movePenTo(44.056, 46.534);
movePenTo(44.974, 46.042);
movePenTo(45.953, 45.661);
movePenTo(46.972, 45.565);
movePenTo(47.91, 45.617);
movePenTo(48.63, 46.087);
movePenTo(49.391, 46.732);
movePenTo(50.002, 47.388);
movePenTo(50.573, 48.07);
movePenTo(50.732, 48.336);
movePenTo(50.829, 48.562);
movePenTo(50.834, 48.844);
movePenTo(50.791, 49.105);
movePenTo(50.395, 49.686);
movePenTo(49.94, 50.22);
movePenTo(49.702, 50.326);
movePenTo(49.43, 50.391);
movePenTo(49.154, 50.349);
movePenTo(48.911, 50.268);
movePenTo(48.651, 50.01);
movePenTo(48.467, 49.751);
movePenTo(48.467, 48.715);
movePenTo(47.916, 48.094);
movePenTo(47.303, 47.587);
movePenTo(46.893, 47.536);
movePenTo(46.563, 47.575);
movePenTo(45.955, 47.789);
movePenTo(45.362, 48.056);
movePenTo(44.949, 48.391);
movePenTo(44.567, 48.865);
movePenTo(44.508, 49.835);
movePenTo(44.563, 50.746);
movePenTo(44.777, 51.25);
movePenTo(45.039, 51.688);
movePenTo(45.686, 52.432);
movePenTo(46.173, 53.423);
movePenTo(49.282, 48.105);
movePenTo(48.641, 47.406);
movePenTo(47.832, 46.744);
movePenTo(47.585, 46.608);
movePenTo(46.991, 46.554);
movePenTo(46.831, 46.559);
movePenTo(46.186, 46.645);
movePenTo(45.392, 46.949);
movePenTo(44.788, 47.257);
movePenTo(44.662, 47.341);
movePenTo(44.225, 47.747);
movePenTo(43.71, 48.357);
movePenTo(43.572, 48.574);
movePenTo(43.523, 49.845);
movePenTo(43.603, 51.046);
movePenTo(43.87, 51.668);
movePenTo(44.286, 52.353);
movePenTo(44.994, 53.163);
movePenTo(45.545, 53.713);
movePenTo(45.69, 53.835);
movePenTo(46.169, 54.076);
movePenTo(46.808, 54.309);
movePenTo(47.544, 54.484);
movePenTo(48.259, 54.606);
movePenTo(49.033, 54.619);
movePenTo(49.895, 54.595);
movePenTo(50.966, 54.514);
movePenTo(51.831, 54.403);
movePenTo(53.025, 54.008);
movePenTo(53.891, 53.656);
movePenTo(54.103, 53.551);
movePenTo(54.642, 53.186);
movePenTo(55.144, 52.769);
movePenTo(55.582, 52.242);
movePenTo(55.859, 51.823);
movePenTo(55.916, 51.707);
movePenTo(56.129, 51.06);
movePenTo(56.292, 50.37);
movePenTo(56.323, 50.168);
movePenTo(56.341, 49.262);
movePenTo(56.31, 48.233);
movePenTo(56.159, 46.511);
movePenTo(56.044, 45.708);
movePenTo(55.828, 44.725);
movePenTo(55.744, 44.479);
movePenTo(54.22, 41.726);
movePenTo(52.717, 39.232);
movePenTo(52.553, 39.002);
movePenTo(52.161, 38.58);
movePenTo(51.68, 38.162);
movePenTo(50.857, 37.588);
movePenTo(49.92, 37.028);
movePenTo(49.589, 36.887);
movePenTo(48.484, 36.641);
movePenTo(47.376, 36.483);
movePenTo(46.324, 36.449);
movePenTo(45.385, 36.473);
movePenTo(44.594, 36.52);
movePenTo(43.63, 36.639);
movePenTo(43.411, 36.687);
movePenTo(41.825, 37.295);
movePenTo(40.205, 38.039);
movePenTo(39.887, 38.235);
movePenTo(39.21, 38.86);
movePenTo(38.71, 39.449);
movePenTo(38.571, 39.641);
movePenTo(37.903, 40.874);
movePenTo(37.46, 41.91);
movePenTo(37.403, 42.084);
movePenTo(37.281, 43.496);
movePenTo(37.239, 45.152);
movePenTo(37.225, 46.371);
movePenTo(37.279, 47.739);
movePenTo(37.33, 48.06);
movePenTo(37.707, 49.19);
movePenTo(38.233, 50.415);
movePenTo(39.703, 53.146);
movePenTo(41.199, 55.696);
movePenTo(41.835, 56.325);
movePenTo(42.551, 56.916);
movePenTo(43.316, 57.486);
movePenTo(44.193, 58.061);
movePenTo(46.228, 58.983);
movePenTo(47.887, 59.606);
movePenTo(48.103, 59.652);
movePenTo(48.932, 59.694);
movePenTo(49.923, 59.628);
movePenTo(51.992, 59.2);
movePenTo(53.375, 58.869);
movePenTo(54.165, 58.772);
  // }
  up();
}

