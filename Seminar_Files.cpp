#include <iostream>
#include <fstream>

const char* FILE_NAME = "database.dat";

struct Student {
	char name[40];
	int age;
	bool isPresent;

};
Student* createStudent();
//void readFromFile();
void printCertainStudent();

int main() {
	FILE* dataBase;
	fopen_s(&dataBase, FILE_NAME, "w");
	if (dataBase == NULL) {
		std::cout << "file open error" << std::endl;
		return 1;
	}

	int needWrite = 1;
	while (needWrite > 0) {
		Student* newStudent = createStudent();
		fwrite(newStudent, sizeof(Student), 1, dataBase);
		std::cout << "Enter \"1\" to create next student and \"0\" to exit: ";
		std::cin >> needWrite;
	}
	
	fclose(dataBase);

	//readFromFile();
	printCertainStudent();
	
	return 0;
}

Student* createStudent() {
	Student* newStudent = new Student; 
	std::cout << "Enter student arguments: " << std::endl;
	
	std::cout << "Name: ";
	std::cin >> newStudent->name;

	std::cout << "Age: ";
	std::cin >> newStudent->age;
	
	std::cout << "fact of presence: ";
	std::cin >> newStudent->isPresent;

	return newStudent; 
}

/*
void readFromFile() {
	FILE* readDataBase;
	fopen_s(&readDataBase, FILE_NAME, "r");
	if (readDataBase == NULL) return;

	struct Student inputBuffer; 
	while (fread(&inputBuffer, sizeof(Student), 1, readDataBase)) {
		printf("%40s %4d %1d\n", inputBuffer.name, inputBuffer.age, inputBuffer.isPresent);
	}

	fclose(readDataBase);
}
*/

void printCertainStudent() {
	FILE* readDataBase;
	fopen_s(&readDataBase, FILE_NAME, "r");
	if (readDataBase == NULL) return;

	Student inputBuffer[5];

	int i = 0;
	while (fread(&inputBuffer[i],sizeof(Student),1, readDataBase)) {
		i++;
	}

	i = 0;
	for (i; i < 5; i++) {
		if (inputBuffer[i].age > 18) printf("%40s %4d %1d\n", inputBuffer[i].name, inputBuffer[i].age, inputBuffer[i].isPresent);
	}

	fclose(readDataBase);
	
}
