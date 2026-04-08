typedef struct{
	char partName[20];
	int partID;
	int speed;
	int acceleration;
	int weight;
	int handling;
	int traction;
}Stats;

typedef struct{
	Stats body;
	Stats wheel;
	Stats glider;
}Vehicle;

typedef struct{
	char itemName[20];
	int itemID;
}Item;

typedef struct{
	char name[20];
	int id;
}IGN;

typedef struct{
	char chcterName[20];
	int chcterID;
	int chcterWeight;
}Character;

typedef struct{
	Item items[2];
	IGN ign;
	Character character;
	Vehicle vehicle;
	int coin;
}User;

typedef struct{
	User data;
	int next;
}Node;

typedef struct{
	node H[MAX];
	int avail
}VHeap;




