//#include <windows.h>
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	char file_name[] = "Demo.txt";
//	HANDLE hFile, hMapping; // дескрипторы файла и объекта отображения
//	int *ptr; // для указателя на массив
//			  // открываем файл для вывода
//	ofstream out(file_name, ios::out | ios::binary);
//	if (!out) {
//		cerr << "File constructor failed." << endl;
//		return 0;
//	}
//	// выводим исходный массив в файл и на консоль
//	cout << "File 'Demo.txt' cozdan" << "\n";
//	system("pause");
//	cout << "Initial array: ";
//	for (int i = 0; i < 10; ++i) {
//		out.write((char*)&a[i], sizeof(int));
//		cout << a[i] << ' ';
//	}
//	cout << endl;
//	// закрываем выходной файл
//	out.close();
//
//	system("pause");
//	// открываем файл для отображения в память
//	hFile = CreateFile((LPCWSTR)file_name, GENERIC_READ | GENERIC_WRITE,
//		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	if (hFile == INVALID_HANDLE_VALUE) {
//		cerr << "Create file failed." << endl;
//		return GetLastError();
//	}
//	cerr << endl << "Descriptor objecta:\t" << hFile << "\n";
//	system("pause");
//	// открываем объект, отображающий файл в память
//	hMapping = CreateFileMapping(
//		hFile, // дескриптор открытого файла
//		NULL, // атрибуты защиты по умолчанию
//		PAGE_READWRITE, // режим доступа
//		0, 0, // размер объекта отображения равен размеру файла
//		NULL); // имя не используем
//	if (!hMapping) {
//		cerr << "Create file mapping failed." << endl;
//		return GetLastError();
//	}
//	cerr << "Descriptor objecta otrajenija:\t" << hMapping << "\n";
//	// создаем вид файла
//	ptr = (int*)MapViewOfFile(
//		hMapping, // дескриптор объекта отображения
//		FILE_MAP_WRITE, // режим доступа к виду
//		0, 0, // отображаем файл с начала
//		0); // отображаем весь файл
//			// изменяем значения элементов массива
//	for (int i = 0; i < 10; ++i)
//		ptr[i] += 10;
//	// отменяем отображение файла в память
//	if (!UnmapViewOfFile(ptr)) {
//		cerr << "Unmap view of file failed." << endl;
//		return GetLastError();
//	}
//	// закрываем объект отображения файла в память
//	if (!CloseHandle(hMapping)) {
//		cerr << "Close file failed." << endl;
//		return GetLastError();
//	}
//	// закрываем файл
//	if (!CloseHandle(hFile)) {
//		cerr << "Close file failed." << endl;
//		return GetLastError();
//	}
//	//
//	// открываем файл для ввода
//	ifstream in(file_name, ios::in | ios::binary);
//	if (!in) {
//		cerr << "File constructor failed." << endl;
//		return 0;
//	}
//	// вводим финальный массив из файла и выводим на консоль
//	cout << endl << "Final array: ";
//	for (int i = 0; i < 10; ++i) {
//		in.read((char*)&a[i], sizeof(int));
//		cout << a[i] << ' ';
//	}
//	cout << endl;
//	// закрываем входной файл
//	in.close();
//	system("pause");
//	return 0;
//}