//#include <windows.h>
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	char file_name[] = "Demo.txt";
//	HANDLE hFile, hMapping; // ����������� ����� � ������� �����������
//	int *ptr; // ��� ��������� �� ������
//			  // ��������� ���� ��� ������
//	ofstream out(file_name, ios::out | ios::binary);
//	if (!out) {
//		cerr << "File constructor failed." << endl;
//		return 0;
//	}
//	// ������� �������� ������ � ���� � �� �������
//	cout << "File 'Demo.txt' cozdan" << "\n";
//	system("pause");
//	cout << "Initial array: ";
//	for (int i = 0; i < 10; ++i) {
//		out.write((char*)&a[i], sizeof(int));
//		cout << a[i] << ' ';
//	}
//	cout << endl;
//	// ��������� �������� ����
//	out.close();
//
//	system("pause");
//	// ��������� ���� ��� ����������� � ������
//	hFile = CreateFile((LPCWSTR)file_name, GENERIC_READ | GENERIC_WRITE,
//		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	if (hFile == INVALID_HANDLE_VALUE) {
//		cerr << "Create file failed." << endl;
//		return GetLastError();
//	}
//	cerr << endl << "Descriptor objecta:\t" << hFile << "\n";
//	system("pause");
//	// ��������� ������, ������������ ���� � ������
//	hMapping = CreateFileMapping(
//		hFile, // ���������� ��������� �����
//		NULL, // �������� ������ �� ���������
//		PAGE_READWRITE, // ����� �������
//		0, 0, // ������ ������� ����������� ����� ������� �����
//		NULL); // ��� �� ����������
//	if (!hMapping) {
//		cerr << "Create file mapping failed." << endl;
//		return GetLastError();
//	}
//	cerr << "Descriptor objecta otrajenija:\t" << hMapping << "\n";
//	// ������� ��� �����
//	ptr = (int*)MapViewOfFile(
//		hMapping, // ���������� ������� �����������
//		FILE_MAP_WRITE, // ����� ������� � ����
//		0, 0, // ���������� ���� � ������
//		0); // ���������� ���� ����
//			// �������� �������� ��������� �������
//	for (int i = 0; i < 10; ++i)
//		ptr[i] += 10;
//	// �������� ����������� ����� � ������
//	if (!UnmapViewOfFile(ptr)) {
//		cerr << "Unmap view of file failed." << endl;
//		return GetLastError();
//	}
//	// ��������� ������ ����������� ����� � ������
//	if (!CloseHandle(hMapping)) {
//		cerr << "Close file failed." << endl;
//		return GetLastError();
//	}
//	// ��������� ����
//	if (!CloseHandle(hFile)) {
//		cerr << "Close file failed." << endl;
//		return GetLastError();
//	}
//	//
//	// ��������� ���� ��� �����
//	ifstream in(file_name, ios::in | ios::binary);
//	if (!in) {
//		cerr << "File constructor failed." << endl;
//		return 0;
//	}
//	// ������ ��������� ������ �� ����� � ������� �� �������
//	cout << endl << "Final array: ";
//	for (int i = 0; i < 10; ++i) {
//		in.read((char*)&a[i], sizeof(int));
//		cout << a[i] << ' ';
//	}
//	cout << endl;
//	// ��������� ������� ����
//	in.close();
//	system("pause");
//	return 0;
//}