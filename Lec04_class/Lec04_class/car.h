class Car {
protected:
	int speed;     //�ӵ�
	char name[40];  //�̸�
public:
	int gear;      //���
	Car() { }         //�⺻ ������
	~Car() {  }       //�Ҹ���
	Car(int s,const char* n, int g) //�Ű������� �ִ� ������
		: speed(s), gear(g) { // ��� �ʱ�ȭ ����Ʈ (������� �ʱ�ȭ)
	 	strcpy_s(name, n);      // ������ �Լ� ��ü (name ��� �ʱ�ȭ)
	}
	void changeGear(int g = 4) { // ��� �ܼ��� �����ϴ� ��� �Լ�
		gear = g;
	}
	void speedUp() {           // ��� �ܼ��� �����ϴ� ��� �Լ�
		 speed += 5;    
	}
	void display() {          // �ڵ����� ������ ȭ�鿡 �����. 
		 printf("[%s] : ���=%d�� �ӵ�=%dkmph\n", name, gear, speed);
	}
	void whereAmI() { printf("��ü �ּ� = %x\n", this);}
    };
	

	