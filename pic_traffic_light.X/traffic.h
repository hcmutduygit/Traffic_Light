// Define pins for traffic lights
#define RED1    RD0     // PORTD, RD0
#define YELLOW1  RD1     // PORTD, RD1
#define GREEN1 RD2     // PORTD, RD2
#define RED2    RD3     
#define YELLOW2  RD4     
#define GREEN2 RD5     

const int ROAD1_TIME = 9000; 
const int ROAD2_TIME = 7000;
const int YELLOW_TIME = 2000;
void Auto_Mode();
void Opposite_State();
void Yellow();
void Midnight_Mode();
void Manual_Mode();

volatile uint8_t exitsign = 0; // To end task when interrupt is triggered
volatile uint8_t turn = 0;  // To change the road turn, only used in manual mode.
volatile uint8_t mode = 0;  // To switch modes. 0 = Auto, 1 = Midnight, 2 = Manual
