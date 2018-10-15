#pragma config(Sensor, S1,     Ultrasonic,     sensorSONAR)
#pragma config(Sensor, S2,     Ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     Ultrasonic,     sensorSONAR)
#pragma config(Motor,  motorA,          right,         tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          left,          tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define MAX_PEG_SIZE 81

#define isEmpty(X)    (X->size == 0)
#define isFull(X)     (X->size == MAX_PEG_SIZE)

float bias_motor = 0;
struct tStackElement
{
  int value;
} tStackElement;

struct tStack
{
  tStackElement elements[MAX_PEG_SIZE];
  int size;
} tStack;


bool push(tStack *stack, int value);
int pop(tStack *stack);
void initStack(tStack *stack);

bool push(tStack *stack, int value)
{
  if (isFull(stack))
  {
    return false;
  }
  stack->elements[stack->size++].value = value;
  return true;
}

int pop(tStack *stack)
{
  if (isEmpty(stack))
  {
    return 0;
  }
  return stack->elements[--stack->size].value;
}

void initStack(tStack *stack)
{
  stack->size = 0;
  memset(stack->elements, 0, sizeof(stack->elements));
}

void clear(tStack *stack)
{
	stack->size = 0;
  memset(stack->elements, 0, sizeof(stack->elements));
}

int empty(tStack *stack)
{
	if (isEmpty(stack))
  {
    return 0;
  }
  else
  {
  	return 1;
  }
}

void beep(int i);
//void updatefloodfill();
void checkstack();
int min2(int a, int b);
int min3(int a, int b, int c);
int min4(int a, int b, int c, int d);
void pushstack();
void changemap();
tStack x1, x2 , y1 , y2;



int Ultra_L = 0;
int Ultra_R = 0;
int Ultra_F = 0;

int wallhorimem[10][9] =
{ {1, 1, 1, 1, 1, 1, 1, 1, 1}, //0,0   0,1
	{0, 0, 0, 0, 0, 0, 0, 0, 0}, //1,0
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int ava[9][9] =
	{{0, 0, 0, 0, 0, 0, 0, 0, 0}, //0,0   0,1
	 {0, 0, 0, 0, 0, 0, 0, 0, 0}, //1,0
	 {0, 0, 0, 0, 0, 0, 0, 0, 0},
	 {0, 0, 0, 0, 0, 0, 0, 0, 0},
	 {0, 0, 0, 0, 0, 0, 0, 0, 0},
	 {0, 0, 0, 0, 0, 0, 0, 0, 0},
	 {0, 0, 0, 0, 0, 0, 0, 0, 0},
	 {0, 0, 0, 0, 0, 0, 0, 0, 0},
	 {0, 0, 0, 0, 0, 0, 0, 0, 0}};

int wallvertmem[9][10] =
{ {1, 0, 0, 0, 0 , 0, 0, 0, 0, 1}, //0,0   0,1
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1}, //1,0
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0 , 0, 0, 0, 0, 1}
};


int car[9][9] =
{ {8, 7, 6, 5, 4, 5, 6, 7, 8}, //0,0   0,1
	{7, 6, 5, 4, 3, 4, 5, 6, 7}, //1,0
	{6, 5, 4, 3, 2, 3, 4, 5, 6},
	{5, 4, 3, 2, 1, 2, 3, 4, 5},
	{4, 3, 2, 1, 0, 1, 2, 3, 4},
	{5, 4, 3, 2, 1, 2, 3, 4, 5},
	{6, 5, 4, 3, 2, 3, 4, 5, 6},
	{7, 6, 5, 4, 3, 4, 5, 6, 7},
	{8, 7, 6, 5, 4, 5, 6, 7, 8}
};

int car1[9][9] =
	{
		{81, 81, 81, 81, 81, 81, 81, 81, 81}, //0,0   0,1
		{81, 81, 81, 81, 81, 81, 81, 81, 81}, //1,0
		{81, 81, 81, 81, 81, 81, 81, 81, 81},
		{81, 81, 81, 81, 81, 81, 81, 81, 81},
		{81, 81, 81, 81, 81, 81, 81, 81, 81},
		{81, 81, 81, 81, 81, 81, 81, 81, 81},
		{81, 81, 81, 81, 81, 81, 81, 81, 81},
		{81, 81, 81, 81, 81, 81, 81, 81, 81},
		{81, 81, 81, 81, 81, 81, 81, 81, 0}};

int car2[9][9] =
	{{8, 7, 6, 5, 4, 5, 6, 7, 8}, //0,0   0,1
	 {7, 6, 5, 4, 3, 4, 5, 6, 7}, //1,0
	 {6, 5, 4, 3, 2, 3, 4, 5, 6},
	 {5, 4, 3, 2, 1, 2, 3, 4, 5},
	 {4, 3, 2, 1, 0, 1, 2, 3, 4},
	 {5, 4, 3, 2, 1, 2, 3, 4, 5},
	 {6, 5, 4, 3, 2, 3, 4, 5, 6},
	 {7, 6, 5, 4, 3, 4, 5, 6, 7},
	 {8, 7, 6, 5, 4, 5, 6, 7, 8}};

int x = 8, y = 8;
int endx = 4, endy = 4;

int avalblock = 0;
int pathblock = 0;
int pattern = 0;
int direction = 0;

void checkwall();
void min2way(int a, int b);
void checkpatndi();
void min3way(int a, int b, int c);
void changemap1();
void countava();

void forward(int i) {
	resetGyro(S3);
	resetMotorEncoder(motorA);
	resetMotorEncoder(motorD);

	int gyro = 0;
	int error , last_error , sum_error = 0;
	int encoder_L =  0;
	int encoder_R = 0;
	int avg_encoder = 0;
	int pid = 0;

	while (avg_encoder < 625) {
		encoder_L = getMotorEncoder(motorD);
		encoder_R = getMotorEncoder(motorA);
		Ultra_R = SensorValue[S1];
		Ultra_L = SensorValue[S4];
		Ultra_F = SensorValue[S2];
		gyro = getGyroDegrees(S3);
		last_error = error;

		if (i == 6 && SensorValue[S4] < 15 && SensorValue[S4] < 15) {
			pid = error * 5;
		} else {
			pid = gyro * 1;
		}

		sum_error += error;
		avg_encoder = (encoder_L + encoder_R) / 2;
		//displayTextLine(0,"%d",encoder_L);
		//displayTextLine(1,"%d",encoder_R);
		pid = pid > 5 ? 5 : pid;
		bias_motor = bias_motor >= 30 ? 30:bias_motor;
		setMotorSpeed(motorA, bias_motor + pid);
		setMotorSpeed(motorD, bias_motor + pid * (-1));
		bias_motor+=0.05;
	}
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);
	if(SensorValue[S2] < 18 && SensorValue[S2] != 10){
		for(int x = 0 ; x < 8000 ; x++){
			int k = (8 - SensorValue[S2]) * (-3);
			setMotorSpeed(motorA, k);
			setMotorSpeed(motorD, k);
		}
	}
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);

}

void turn_left() {
	resetGyro(S3);
	int gyro = 0, pid = 0 ,x_error = 0,y_error = 0;
	for (int i = 0 ; i < 10000 ; i++) {
		x_error = gyro;
		y_error += gyro;
		gyro = 87 + getGyroDegrees(S3);
		pid = gyro * 0.5 + (gyro - x_error) * 15;
		setMotorSpeed(motorA, pid);
		setMotorSpeed(motorD, pid * (-1));
	}

	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);
	if(SensorValue[S2] < 18 && SensorValue[S2] != 10){
		for(int x = 0 ; x < 8000 ; x++){
			int k = (8 - SensorValue[S2]) * (-3);
			setMotorSpeed(motorA, k);
			setMotorSpeed(motorD, k);
		}
	}
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);

}

void turn_right() {
	resetGyro(S3);
	int gyro = 0, pid = 0 ,x_error = 0,y_error = 0;
	for (int i = 0 ; i < 10000 ; i++) {
		x_error = gyro;
		y_error += gyro;
		gyro = -87 + getGyroDegrees(S3);
		pid = gyro * 0.5 + (gyro - x_error) * 15;
		setMotorSpeed(motorA, pid);
		setMotorSpeed(motorD, pid * (-1));
	}
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);
	if(SensorValue[S2] < 18 && SensorValue[S2] != 10){
		for(int x = 0 ; x < 8000 ; x++){
			int k = (8 - SensorValue[S2]) * (-3);
			setMotorSpeed(motorA, k);
			setMotorSpeed(motorD, k);
		}
	}
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);
}


task main()
{
	///////////////////////////////////////////
	initStack(&x1);
	initStack(&x2);
	initStack(&y1);
	initStack(&y2);

	resetGyro(S3);

	push(&x1,x);
	push(&y1,y);

	while (x != endx || y != endy) {

		for(int a = 0; a < 9; a++){
			displayTextLine(a,"%d %d %d %d %d %d %d %d",ava[a][0],ava[a][1],ava[a][2],ava[a][3],ava[a][4],ava[a][5],ava[a][6],ava[a][7],ava[a][8]);
		}

		beep(1);
		Ultra_R = SensorValue[S1];
		Ultra_L = SensorValue[S4];
		Ultra_F = SensorValue[S2];
		//displayTextLine(0,"%d",check_pattern(Ultra_L,Ultra_R,Ultra_F));
		ava[x][y] = 1;
		//printf("%d : (%d,%d) \n", direction, x, y);
		pattern = 0;
		checkwall();
		pushstack();
		checkstack();
		checkpatndi();

	}
	clear(&x1);
	clear(&y1);
	clear(&x2);
	clear(&y2);
	changemap();
	changemap();
	//printcar();
	x = 4;
	y = 4;
	endx = 8;
	endy = 8;
	push(&x1,x);
	push(&y1,y);

	while (x != endx || y != endy)
	{
		beep(1);
		Ultra_R = SensorValue[S1];
		Ultra_L = SensorValue[S4];
		Ultra_F = SensorValue[S2];
		//displayTextLine(0,"%d",check_pattern(Ultra_L,Ultra_R,Ultra_F));
		ava[x][y] = 1;
		//printf("%d : (%d,%d) \n", direction, x, y);
		pattern = 0;
		checkwall();
		pushstack();
		checkstack();
		checkpatndi();
	}



	if(direction == 3){
		turn_left();
		turn_left();
		direction = 0;
	}else if(direction == 2){
		turn_left();
		direction = 0;
	}

	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);
	beep(10);

	x = 8;
	y = 8;
	endx = 4;
	endy = 4;
	for (int i = 0; i < 10; i++)
	{
		changemap1();
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			car[i][j] = car2[i][j];
		}
	}

	while (x != endx || y != endy)
	{
		pattern = 0;
		checkwall();
		pushstack();
		checkstack();
		checkpatndi();
		pathblock += 1;
	}
	countava();
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);
	beep(20);


	////////////////////////////////////////////
}

void countava()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (ava[i][j] == 1)
			{
				avalblock += 1;
			}
		}
	}
}


void checkwall() {

	Ultra_R = SensorValue[S1];
	Ultra_L = SensorValue[S4];
	Ultra_F = SensorValue[S2];

	switch (direction) {
	case 0 : //north
		if (Ultra_F < 15) {
			//printf("0 : have a front wall\n");
			wallhorimem[x][y] = 1;
			pattern += 1 ; //#front
			setMotorSpeed(motorC, 100);
			setMotorSpeed(motorB, 100);
			sleep(100);
			setMotorSpeed(motorC, 0);
			setMotorSpeed(motorB, 0);
			sleep(100);

		}
		sleep(200);
		if (Ultra_L < 14) {
			//printf("0 : have a left wall\n");
			wallvertmem[x][y] = 1;
			pattern += 2 ; //#left
			setMotorSpeed(motorB, 100);
			sleep(100);
			setMotorSpeed(motorB, 0);
			sleep(100);
		}
		sleep(200);
		if (Ultra_R < 14) {
			//printf("0 : have a right wall\n");
			wallvertmem[x][y + 1] = 1;
			pattern += 4 ; //#right
			setMotorSpeed(motorC, 100);
			sleep(100);
			setMotorSpeed(motorC, 0);
			sleep(100);
		} sleep(200); break;
	case 1 : //east
		if (Ultra_F < 15) {
			//printf("1 : have a front wall\n");
			wallvertmem[x][y] = 1;
			pattern += 1 ; //#front
		}
		if (Ultra_L < 14) {
			//printf("1 : have a left wall\n");
			wallhorimem[x + 1][y] = 1;
			pattern += 2 ; //#left
		}
		if (Ultra_R < 14) {
			//printf("1 : have a right wall\n");
			wallhorimem[x][y] = 1;
			pattern += 4 ; //#right
		} break;
	case 2 : //west
		if (Ultra_F < 15) {
			//printf("2 : have a front wall\n");
			wallvertmem[x][y + 1] = 1;
			pattern += 1 ; //#front
		}
		if (Ultra_L < 14) {
			//printf("2 : have a left wall\n");
			wallhorimem[x][y] = 1;
			pattern += 2 ; //#left

		}
		if (Ultra_R < 14) {
			//printf("2 : have a right wall\n");
			wallhorimem[x + 1][y] = 1;
			pattern += 4 ; //#right
		} break;
	default : //south
		if (Ultra_F < 14) {
			//printf("3 : have a front wall\n");
			wallhorimem[x + 1][y] = 1;
			pattern += 1 ; //#front
		}
		if (Ultra_L < 14) {
			//printf("3 : have a left wall\n");
			wallvertmem[x][y + 1] = 1;
			pattern += 2 ; //#left
		}
		if (Ultra_R < 14) {
			//printf("3 : have a right wall\n");
			wallvertmem[x][y] = 1;
			pattern += 4 ; //#right
		} break;
	}
}

void beep(int i) {
	for (int j = -1; j < i ; j++) {
		playTone(4000, 10);
		sleep(200);
	}
}

void min2way(int a, int b) {
	if (a <= b) {
		switch (direction) {
		case 0:   //direction = 0
			//beep(1);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_left(); forward(pattern); y--; direction = 1;  break;//left,right
			case 2: forward(pattern);  x--; direction = 0;  break;//front,right
			case 6:  forward(pattern); x--; direction = 0; break;
			default: forward(pattern);   x--; direction = 0;  break;//front,left
			} break;
		case 1:   //direction = 1
			//beep(2);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_left(); forward(pattern);   x++; direction = 3;  break;//left,right
			case 2: forward(pattern);  y--; direction = 1;  break;//front,right
			case 6: forward(pattern); y--; direction = 1;  break;
			default: forward(pattern);   y--; direction = 1;  break;//front,left
			} break;
		case 2:   //direction = 2
			//beep(3);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_left(); forward(pattern);   x--; direction = 0;  break;//left,right
			case 2: forward(pattern);  y++; direction = 2;  break;//front,right
			case 6:  forward(pattern); y++; direction = 2; break;
			default: forward(pattern);   y++; direction = 2;  break;//front,left
			} break;
		default:    //direction = 3
			//beep(4);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_left(); forward(pattern);  y++;  direction = 2;  break;//left,right
			case 2: forward(pattern);  x++; direction = 3;  break;//front,right
			case 6: forward(pattern); x++; direction = 3;  break;
			default: forward(pattern);   x++; direction = 3;  break;//front,left
			} break;
		}

		} else {
		switch (direction) {
		case 0:   //direction = 0
			//beep(5);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_right(); forward(pattern); y++;  direction = 2;  break;//left,right
			case 2: turn_right(); forward(pattern); y++;  direction = 2;  break;//front,right
			case 6: turn_left(); turn_left(); forward(pattern); x++; direction = 3; break;
			default: turn_left(); forward(pattern); y--;  direction = 1;  break;//front,left
			} break;
		case 1:   //direction = 1
			//beep(6);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_right(); forward(pattern); x--;  direction = 0;  break;//left,right
			case 2: turn_right(); forward(pattern); x--;  direction = 0;  break;//front,right
			case 6: turn_left(); turn_left(); forward(pattern); y++; direction = 2; break;
			default: turn_left(); forward(pattern); x++;  direction = 3;  break;//front,left
			} break;
		case 2:   //direction = 2
			//beep(7);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_right(); forward(pattern); x++;  direction = 3;  break;//left,right
			case 2: turn_right(); forward(pattern);  x++; direction = 3;  break;//front,right
			case 6: turn_left(); turn_left(); forward(pattern); y--; direction = 1; break;
			default: turn_left(); forward(pattern); x--;  direction = 0;  break;//front,left
			} break;
		default:    //direction = 3
			//beep(8);sleep(100);
			switch (pattern) {
				//beep(pattern);
			case 1: turn_right(); forward(pattern); y--;  direction = 1;  break;//left,right
			case 2: turn_right(); forward(pattern); y--;  direction = 1;  break;//front,right
			case 6: turn_left(); turn_left(); forward(pattern); x--; direction = 0; break;
			default: turn_left(); forward(pattern); y++;  direction = 2;  break;//front,left
			} break;
		}
	}
}

void min3way(int a , int b, int c) { //front,left,right
	if (a != b && a != c && b != c) {
		if (a < b && a < c) { //go front
			switch (direction) {
			case 0: //printf("0 : ");//north
				forward(pattern);     x--;  direction = 0;  break;
			case 1: //printf("1 : ");//east
				forward(pattern);     y--;  direction = 1;  break;
			case 2: //printf("2 : ");//west
				forward(pattern);     y++;  direction = 2;  break;
			default: //printf("3 : ");//south
				forward(pattern);     x++;  direction = 3;  break;
			}
			} else if (b < a && b < c) { //go left
			switch (direction) {
			case 0: //printf("0 : ");//north
				turn_left();  forward(pattern); y--;  direction = 1;  break;
			case 1: //printf("1 : ");//east
				turn_left();  forward(pattern); x++;  direction = 3;  break;
			case 2: //printf("2 : ");//west
				turn_left();  forward(pattern); x--;  direction = 0;  break;
			default: //printf("3 : ");//south
				turn_left();  forward(pattern); y++;  direction = 2;  break;
			}
			} else { //go right
			switch (direction) {
			case 0: //printf("0 : ");//north
				turn_right(); forward(pattern);   y++;  direction = 2;  break;
			case 1: //printf("1 : ");//east
				turn_right(); forward(pattern);   x--;  direction = 0;  break;
			case 2: //printf("2 : ");//west
				turn_right(); forward(pattern);   x++;  direction = 3;  break;
			default: //printf("3 : ");//south
				turn_right(); forward(pattern);   y--;  direction = 1;  break;
			}
		}
	}
	else {
		switch (direction) {
		case 0: //printf("0 : ");//north
			forward(pattern);     x--;  direction = 0;  break;
		case 1: //printf("1 : ");//east
			forward(pattern);     y--;  direction = 1;  break;
		case 2: //printf("2 : ");//west
			forward(pattern);     y++;  direction = 2;  break;
		default: //printf("3 : ");//south
			forward(pattern);     x++;  direction = 3;  break;
		}

	}
}

void checkpatndi() {
	switch (direction) {
	case 0: //printf("0 : ");//north
		switch (pattern) {
		case 0: min3way(car[x - 1][y], car[x][y - 1], car[x][y + 1]); break;
		case 1: min2way(car[x][y - 1], car[x][y + 1]); break;
		case 2: min2way(car[x - 1][y], car[x][y + 1]); break;
		case 4: min2way(car[x - 1][y], car[x][y - 1]); break;
		case 3: turn_right(); forward(pattern);       y++;  direction = 2; break; //front+left
		case 5: turn_left();  forward(pattern);       y--;  direction = 1; break; //front+right
		case 6: forward(pattern); x--;  direction = 0; break;//min2way(car[x - 1][y], car[x + 1][y]); break;//left+right
		default:  turn_left(); turn_left(); forward(pattern);         x++;  direction = 3; break; //front+left+right
		} break;
	case 1: //printf("1 : ");//east
		switch (pattern) {
		case 0: min3way(car[x][y - 1], car[x + 1][y], car[x - 1][y]); break;
		case 1: min2way(car[x + 1][y], car[x - 1][y]); break;
		case 2: min2way(car[x][y - 1], car[x - 1][y]); break;
		case 4: min2way(car[x][y - 1], car[x + 1][y]); break;
		case 3: turn_right(); forward(pattern);       x--;  direction = 0;  break;//front+left
		case 5: turn_left();  forward(pattern);     x++;  direction = 3;  break;//front+right
		case 6: forward(pattern); y--;  direction = 1; break;//min2way(car[x][y - 1], car[x][y + 1]); break;//left+right
		default:  turn_left(); turn_left(); forward(pattern);         y++;  direction = 2;  break; //front+left+right
		} break;
	case 2: //printf("2 : ");//west
		switch (pattern) {
		case 0: min3way(car[x][y + 1], car[x - 1][y], car[x + 1][y]); break;
		case 1: min2way(car[x - 1][y], car[x + 1][y]); break;
		case 2: min2way(car[x][y + 1], car[x + 1][y]); break;
		case 4: min2way(car[x][y + 1], car[x - 1][y]); break;
		case 3: turn_right();  forward(pattern);        x++;  direction = 3;  break;//front+left
		case 5: turn_left();   forward(pattern);      x--;  direction = 0;  break;//front+right
		case 6: forward(pattern); y++;  direction = 2; break;//min2way(car[x][y + 1], car[x][y - 1]); break;//left+right
		default:  turn_left(); turn_left(); forward(pattern);         y--;  direction = 1;  break; //front+left+right
		} break;
	default: //printf("3 : ");//south
		switch (pattern) {
		case 0: min3way(car[x + 1][y], car[x][y + 1], car[x][y - 1]); break;
		case 1: min2way(car[x][y + 1], car[x][y - 1]); break;
		case 2: min2way(car[x + 1][y], car[x][y - 1]); break;
		case 4: min2way(car[x + 1][y], car[x][y + 1]); break;
		case 3: turn_right(); forward(pattern);       y--;  direction = 1;  break;//front+left
		case 5: turn_left();  forward(pattern);     y++;  direction = 2;  break;//front+right
		case 6: forward(pattern); x++;  direction = 3; break;//min2way(car[x + 1][y], car[x - 1][y]);  break;//left+right
		default:  turn_left(); turn_left(); forward(pattern);         x--;  direction = 0;  break; //front+left+right
		} break;
	}
}


void checkstack()
{
	int bufferx = 0;
	int buffery = 0;
	int checkw = 0;
	while (!empty(&x1) && !empty(&y1))
	{
		checkw = 0;
		bufferx = pop(&x1);
		buffery = pop(&y1);
		if (bufferx == endx && buffery == endy)
		{
			break;
		}
		pop(&x1);
		pop(&y1);
		push(&x2,bufferx);
		push(&y2,buffery);
		//printf("(%d,%d) ", bufferx, buffery);
		if (wallhorimem[bufferx][buffery] == 1)
		{
			//printf("*front ");
			checkw += 1; //#front
		}
		if (wallvertmem[bufferx][buffery] == 1)
		{
			//printf("*left ");
			checkw += 2; //#left
		}
		if (wallvertmem[bufferx][buffery + 1] == 1)
		{
			//printf("*right ");
			checkw += 4; //#right
		}
		if (wallhorimem[bufferx + 1][buffery] == 1)
		{
			//printf("*back ");
			checkw += 8; //#front
		}
		//printf("\n");
		switch (checkw)
		{
		case 0: //front,left,right,back
			car[bufferx][buffery] = min4(car[bufferx - 1][buffery], car[bufferx][buffery - 1], car[bufferx][buffery + 1], car[bufferx + 1][buffery]);
			break;
		case 1: //left,right,back
			car[bufferx][buffery] = min3(car[bufferx][buffery - 1], car[bufferx][buffery + 1], car[bufferx + 1][buffery]);
			break;
		case 2: //front,right,back
			car[bufferx][buffery] = min3(car[bufferx - 1][buffery], car[bufferx][buffery + 1], car[bufferx + 1][buffery]);
			break;
		case 3: //back,right
			car[bufferx][buffery] = min2(car[bufferx][buffery + 1], car[bufferx + 1][buffery]);
			break;
		case 4: //front,left,back
			car[bufferx][buffery] = min3(car[bufferx - 1][buffery], car[bufferx][buffery - 1], car[bufferx + 1][buffery]);
			break;
		case 5: //left,back
			car[bufferx][buffery] = min2(car[bufferx][buffery - 1], car[bufferx + 1][buffery]);
			break;
		case 6: //front,back
			car[bufferx][buffery] = min2(car[bufferx - 1][buffery], car[bufferx + 1][buffery]);
			break;
		case 7: //back
			car[bufferx][buffery] = car[bufferx + 1][buffery] + 1;
			break;
		case 8: //front,left,right
			car[bufferx][buffery] = min3(car[bufferx - 1][buffery], car[bufferx][buffery - 1], car[bufferx][buffery + 1]);
			break;
		case 9: //left,right
			car[bufferx][buffery] = min2(car[bufferx][buffery - 1], car[bufferx][buffery + 1]);
			break;
		case 10: //front,right
			car[bufferx][buffery] = min2(car[bufferx - 1][buffery], car[bufferx][buffery + 1]);
			break;
		case 11: //right
			car[bufferx][buffery] = car[bufferx][buffery + 1] + 1;
			break;
		case 12: //front,left
			car[bufferx][buffery] = min2(car[bufferx - 1][buffery], car[bufferx][buffery - 1]);
			break;
		case 13: //left
			car[bufferx][buffery] = car[bufferx][buffery - 1] + 1;
			break;
		case 14: //front
			car[bufferx][buffery] = car[bufferx - 1][buffery] + 1;
			break;
		default: //no
			break;
		}
	}

	while (!empty(&x1) && !empty(&y1))
	{
		if (bufferx == endx && buffery == endy)
		{
			break;
		}
		bufferx = pop(&x2);
		buffery = pop(&y2);
		pop(&x2);
		pop(&y2);
		push(&x1,bufferx);
		push(&y1,buffery);
	}
}

int min2(int a, int b)
{
	if (a < b)
	{
		return a + 1;
	}
	else
	{
		return b + 1;
	}
}

int min3(int a, int b, int c)
{
	if (((a < b) && (a < c)) || ((a == c) && (a < b)) || ((a == b) && (a < c)))
	{
		return a + 1;
	}
	else if ((b < a) && (b < c) || ((b == c) && (b < a)))
	{
		return b + 1;
	}
	else if ((c < a) && (c < b))
	{
		return c + 1;
	}
	else
	{
		return a + 1;
	}
}

int min4(int a, int b, int c, int d)
{
	if (((a < b) && (a < c) && (a < d)) || ((a == b) && (a < c) && (a < d)) || ((a == c) && (a < b) && (a < d)) || ((a == d) && (a < b) && (a < c)))
	{
		return a + 1;
	}
	else if (((b < a) && (b < c) && (b < d)) || ((b == c) && (b < a) && (b < d)) || ((b == d) && (b < a) && (b < c)))
	{
		return b + 1;
	}
	else if ((c < a) && (c < b) && (c < d) || ((c == d) && (c < a) && (c < b)))
	{
		return c + 1;
	}
	else if ((d < a) && (d < b) && (d < c))
	{
		return d + 1;
	}
	else
	{
		return a + 1;
	}
}

void pushstack()
{
	switch (direction)
	{
	case 0:
		switch (pattern)
		{
		case 0: //no wall 3 way
			push(&x1,x - 1);
			push(&y1,y);
			push(&x1,x);
			push(&y1,y - 1);
			push(&x1,x);
			push(&y1,y + 1);
			break;
		case 1: //2 way left,right
			push(&x1,x);
			push(&y1,y - 1);
			push(&x1,x);
			push(&y1,y + 1);
			break;
		case 2: //2 way front,right
			push(&x1,x - 1);
			push(&y1,y);
			push(&x1,x);
			push(&y1,y + 1);
			break;
		case 4: //2 way front,left
			push(&x1,x - 1);
			push(&y1,y);
			push(&x1,x);
			push(&y1,y - 1);
			break;
		case 3: //right
			push(&x1,x);
			push(&y1,y + 1);
			break;
		case 5: //left
			push(&x1,x);
			push(&y1,y - 1);
			break;
		case 6: // front
			push(&x1,x - 1);
			push(&y1,y);
			break;
		default: //U turn
			break;
		}
		break;
	case 1:
		switch (pattern)
		{
		case 0: //no wall 3 way
			push(&x1,x);
			push(&y1,y - 1);
			push(&x1,x + 1);
			push(&y1,y);
			push(&x1,x - 1);
			push(&y1,y);
			break;
		case 1: //2 way left,right
			push(&x1,x + 1);
			push(&y1,y);
			push(&x1,x - 1);
			push(&y1,y);
			break;
		case 2: //2 way front,right
			push(&x1,x);
			push(&y1,y - 1);
			push(&x1,x - 1);
			push(&y1,y);
			break;
		case 4: //2 way front,left
			push(&x1,x);
			push(&y1,y - 1);
			push(&x1,x + 1);
			push(&y1,y);
			break;
		case 3: //right
			push(&x1,x - 1);
			push(&y1,y);
			break;
		case 5: //left
			push(&x1,x + 1);
			push(&y1,y);
			break;
		case 6: // front
			push(&x1,x);
			push(&y1,y - 1);
			break;
		default: //U turn
			break;
		}
		break;
	case 2:
		switch (pattern)
		{
		case 0: //no wall 3 way
			push(&x1,x);
			push(&y1,y + 1);
			push(&x1,x - 1);
			push(&y1,y);
			push(&x1,x + 1);
			push(&y1,y);
			break;
		case 1: //2 way left,right
			push(&x1,x - 1);
			push(&y1,y);
			push(&x1,x + 1);
			push(&y1,y);
			break;
		case 2: //2 way front,right
			push(&x1,x);
			push(&y1,y + 1);
			push(&x1,x + 1);
			push(&y1,y);
			break;
		case 4: //2 way front,left
			push(&x1,x);
			push(&y1,y + 1);
			push(&x1,x - 1);
			push(&y1,y);
			break;
		case 3: //right
			push(&x1,x + 1);
			push(&y1,y);
			break;
		case 5: //left
			push(&x1,x - 1);
			push(&y1,y);
			break;
		case 6: // front
			push(&x1,x);
			push(&y1,y + 1);
			break;
		default: //U turn
			break;
		}
		break;
	default:
		switch (pattern)
		{
		case 0: //no wall 3 way
			push(&x1,x + 1);
			push(&y1,y);
			push(&x1,x);
			push(&y1,y + 1);
			push(&x1,x);
			push(&y1,y - 1);
			break;
		case 1: //2 way left,right
			push(&x1,x);
			push(&y1,y + 1);
			push(&x1,x);
			push(&y1,y - 1);
			break;
		case 2: //2 way front,right
			push(&x1,x + 1);
			push(&y1,y);
			push(&x1,x);
			push(&y1,y - 1);
			break;
		case 4: //2 way front,left
			push(&x1,x + 1);
			push(&y1,y);
			push(&x1,x);
			push(&y1,y + 1);
			break;
		case 3: //right
			push(&x1,x);
			push(&y1,y - 1);
			break;
		case 5: //left
			push(&x1,x);
			push(&y1,y + 1);
			break;
		case 6: // front
			push(&x1,x + 1);
			push(&y1,y);
			break;
		default: //U turn
			break;
		}
		break;
	}
}

void changemap()
{
	int checkw = 0;
	for (int buffery = 8; buffery >= 0; buffery--)
	{
		for (int bufferx = 8; bufferx >= 0; bufferx--)
		{
			checkw = 0;
			if (wallhorimem[bufferx][buffery] == 1)
			{
				checkw += 1; //#front
			}
			if (wallvertmem[bufferx][buffery] == 1)
			{
				checkw += 2; //#left
			}
			if (wallvertmem[bufferx][buffery + 1] == 1)
			{
				checkw += 4; //#right
			}
			if (wallhorimem[bufferx + 1][buffery] == 1)
			{
				checkw += 8; //#front
			}
			switch (checkw)
			{
			case 0: //front,left,right,back
				car1[bufferx][buffery] = min4(car1[bufferx - 1][buffery], car1[bufferx][buffery - 1],
											  car1[bufferx][buffery + 1], car1[bufferx + 1][buffery]);
				break;
			case 1: //left,right,back
				car1[bufferx][buffery] = min3(car1[bufferx][buffery - 1], car1[bufferx][buffery + 1], car1[bufferx + 1][buffery]);
				break;
			case 2: //front,right,back
				car1[bufferx][buffery] = min3(car1[bufferx - 1][buffery], car1[bufferx][buffery + 1], car1[bufferx + 1][buffery]);
				break;
			case 3: //back,right
				car1[bufferx][buffery] = min2(car1[bufferx][buffery + 1], car1[bufferx + 1][buffery]);
				break;
			case 4: //front,left,back
				car1[bufferx][buffery] = min3(car1[bufferx - 1][buffery], car1[bufferx][buffery - 1], car1[bufferx + 1][buffery]);
				break;
			case 5: //left,back
				car1[bufferx][buffery] = min2(car1[bufferx][buffery - 1], car1[bufferx + 1][buffery]);
				break;
			case 6: //front,back
				car1[bufferx][buffery] = min2(car1[bufferx - 1][buffery], car1[bufferx + 1][buffery]);
				break;
			case 7: //back
				car1[bufferx][buffery] = car1[bufferx + 1][buffery] + 1;
				break;
			case 8: //front,left,right
				car1[bufferx][buffery] = min3(car1[bufferx - 1][buffery], car1[bufferx][buffery - 1], car1[bufferx][buffery + 1]);
				break;
			case 9: //left,right
				car1[bufferx][buffery] = min2(car1[bufferx][buffery - 1], car1[bufferx][buffery + 1]);
				break;
			case 10: //front,right
				car1[bufferx][buffery] = min2(car1[bufferx - 1][buffery], car1[bufferx][buffery + 1]);
				break;
			case 11: //right
				car1[bufferx][buffery] = car1[bufferx][buffery + 1] + 1;
				break;
			case 12: //front,left
				car1[bufferx][buffery] = min2(car1[bufferx - 1][buffery], car1[bufferx][buffery - 1]);
				break;
			case 13: //left
				car1[bufferx][buffery] = car1[bufferx][buffery - 1] + 1;
				break;
			case 14: //front
				car1[bufferx][buffery] = car1[bufferx - 1][buffery] + 1;
				break;
			default: //no
				break;
			}
			if (bufferx == 8 && buffery == 8)
			{
				car1[8][8] = 0;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			car[i][j] = car1[i][j];
		}
	}
}

void changemap1()
{
	int checkw = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			checkw = 0;
			if (wallhorimem[i][j] == 1)
			{
				checkw += 1; //#front
			}
			if (wallvertmem[i][j] == 1)
			{
				checkw += 2; //#left
			}
			if (wallvertmem[i][j + 1] == 1)
			{
				checkw += 4; //#right
			}
			if (wallhorimem[i + 1][j] == 1)
			{
				checkw += 8; //#front
			}
			switch (checkw)
			{
			case 0: //front,left,right,back
				car2[i][j] = min4(car2[i - 1][j], car2[i][j - 1],
								  car2[i][j + 1], car2[i + 1][j]);
				break;
			case 1: //left,right,back
				car2[i][j] = min3(car2[i][j - 1], car2[i][j + 1], car2[i + 1][j]);
				break;
			case 2: //front,right,back
				car2[i][j] = min3(car2[i - 1][j], car2[i][j + 1], car2[i + 1][j]);
				break;
			case 3: //back,right
				car2[i][j] = min2(car2[i][j + 1], car2[i + 1][j]);
				break;
			case 4: //front,left,back
				car2[i][j] = min3(car2[i - 1][j], car2[i][j - 1], car2[i + 1][j]);
				break;
			case 5: //left,back
				car2[i][j] = min2(car2[i][j - 1], car2[i + 1][j]);
				break;
			case 6: //front,back
				car2[i][j] = min2(car2[i - 1][j], car2[i + 1][j]);
				break;
			case 7: //back
				car2[i][j] = car2[i + 1][j] + 1;
				break;
			case 8: //front,left,right
				car2[i][j] = min3(car2[i - 1][j], car2[i][j - 1], car2[i][j + 1]);
				break;
			case 9: //left,right
				car2[i][j] = min2(car2[i][j - 1], car2[i][j + 1]);
				break;
			case 10: //front,right
				car2[i][j] = min2(car2[i - 1][j], car2[i][j + 1]);
				break;
			case 11: //right
				car2[i][j] = car2[i][j + 1] + 1;
				break;
			case 12: //front,left
				car2[i][j] = min2(car2[i - 1][j], car2[i][j - 1]);
				break;
			case 13: //left
				car2[i][j] = car2[i][j - 1] + 1;
				break;
			case 14: //front
				car2[i][j] = car2[i - 1][j] + 1;
				break;
			default: //no
				car2[i][j] = 81;
				break;
			}
			if (i == 4 && j == 4)
			{
				car2[4][4] = 0;
			}
		}
	}
}
