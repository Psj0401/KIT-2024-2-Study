#include<stdio.h>
#include<stdlib.h>

int main() {
    int total_seconds;

    // 초 입력받기
    printf("총 초를 입력하세요: ");
    scanf("%d", &total_seconds);

    int time_units[] = {86400, 3600, 60}; // 1일 = 86400초, 1시간 = 3600초, 1분 = 60초
    int print_time[4];                   // 출력할 결과를 저장할 배열 (일, 시간, 분, 초)

    // 반복문을 사용하여 일, 시간, 분 계산
    for (int i = 0; i < 3; i++) {
        print_time[i] = total_seconds / time_units[i];   // 각 시간 단위 계산
        total_seconds %= time_units[i];                   // 남은 초 계산
    }
    /*
        10000을 입력받았을 때, 일 : 10000 / 86400 = 0(일) , 나머지 10000 = total_second
                          시간 : 10000 / 3600 = 2(시간), 나머지 2800 = "
                           분 : 2800 / 60 = 46(분), 나머지 40 = 초
    */
    
    print_time[3] = total_seconds; // 마지막 남은 초 

    // 양식에 맞게 출력
    printf("---------- Converted Informtion -----------\n");
    printf("%d days, %d hours %d minutes, %d seconds\n",print_time[0],print_time[1],print_time[2],print_time[3]);
    printf("-------------------------------------------\n");

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int total_seconds;

    cout << "총 초를 입력하세요: ";
    cin >> total_seconds;

    int time_units[3] = {86400, 3600, 60}; 
    int print_time[4];

    for (int i = 0; i < 3; i++) {
        print_time[i] = total_seconds / time_units[i];
        total_seconds %= time_units[i];                  
    }

    print_time[3] = total_seconds;

    cout << "---------- Converted Information -----------" << endl;
    cout << print_time[0] << " days, " << print_time[1] << " hours, " 
         << print_time[2] << " minutes, " << print_time[3] << " seconds" << endl;
    cout << "-------------------------------------------" << endl;

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

void swap(double &a, double &b)
{ 
    double tmp = a; 
    a=b;
    b=tmp; 
}

int main()
{
    double num_1 = 1, num_2 = 2;

    swap(num_1, num_2);
    printf("%f, %f",num_1,num_2);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

//(1)
struct Person {
    string name;
    int age;
    float height;
    float weight;
};

int main() {
    // (2)
    string name_info[10] = {"Brain", "Jessica", "James", "Eric", "John", "Tom", "Tomy", "Alice", "Bob", "Carol"};
    int age_info[10] = {24, 22, 30, 28, 35, 40, 25, 27, 32, 29};
    float height_info[10] = {180, 165, 170, 172, 168, 175, 169, 181, 163, 177};
    float weight_info[10] = {70, 55, 65, 68, 62, 75, 57, 73, 60, 80};

    int num_persons;
    
    // (3) 사용자로부터 입력받은 인원 수 처리
    cout << "인원 수를 입력하시오. (1-10): ";
    cin >> num_persons;

    if (num_persons < 1 || num_persons > 10) {
        num_persons = 1;  // 잘못된 입력일 경우 1로 설정
    }

    // (4) 동적 메모리 할당을 통한 구조체 배열 생성
    Person* persons = new Person[num_persons];

    // (5) 데이터베이스의 정보를 구조체 배열에 할당
    for (int i = 0; i < num_persons; ++i) {
        persons[i].name = name_info[i];
        persons[i].age = age_info[i];
        persons[i].height = height_info[i];
        persons[i].weight = weight_info[i];
    }

    // (6) 구조체 배열의 개인 정보를 출력
    for (int i = 0; i < num_persons; ++i) {
        cout << "Name: " << persons[i].name << endl;
        cout << "Age: " << persons[i].age << endl;
        cout << "Height: " << persons[i].height << " cm" << endl;
        cout << "Weight: " << persons[i].weight << " kg" << endl;
        cout << "--------------------------" << endl;
    }

    // 동적 메모리 해제
    delete[] persons;

    return 0;
}

#include <iostream>

int main() {
    int N = 1000; // 행렬과 벡터의 크기 설정 (N = 1000)

    // 행렬 A를 동적으로 할당 (1000x1000 크기의 2차원 배열)
    double** A = new double*[N]; // 행 크기만큼의 포인터 배열 할당
    for (int i = 0; i < N; ++i) {
        A[i] = new double[N]; // 각 행마다 N개의 열 할당
    }

    // 벡터 V를 동적으로 할당 (1000 크기의 1차원 배열)
    double* V = new double[N]; // 크기가 N인 벡터 V를 할당

    // 결과 벡터 R을 동적으로 할당 (1000 크기의 1차원 배열)
    double* R = new double[N]; // 크기가 N인 결과 벡터 R을 할당

    // 행렬 A의 값을 초기화 (A[ii][jj] = (ii + jj), ii와 jj는 1부터 시작)
    for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            A[ii][jj] = (ii + 1) + (jj + 1); // 문제에서 요구한 대로 ii와 jj는 1부터 시작하므로 +1
        }
    }

    // 벡터 V의 값을 초기화 (V[ii] = ii, ii는 1부터 시작)
    for (int ii = 0; ii < N; ++ii) {
        V[ii] = ii + 1; // 벡터 V의 값도 1부터 시작하도록 +1
    }

    // 결과 벡터 R을 0으로 초기화 (행렬-벡터 곱의 결과를 저장할 벡터)
    for (int ii = 0; ii < N; ++ii) {
        R[ii] = 0.0; // R의 초기 값은 0으로 설정
    }

    // 행렬 A와 벡터 V의 곱을 계산하여 결과 벡터 R에 저장
    for (int ii = 0; ii < N; ++ii) { // A의 각 행에 대해
        for (int jj = 0; jj < N; ++jj) { // A의 각 열과 벡터 V의 대응되는 요소 곱셈
            R[ii] += A[ii][jj] * V[jj]; // A[ii][jj]와 V[jj]의 곱을 R[ii]에 더함
        }
    }

    // 결과 벡터 R의 모든 요소의 합을 계산
    double sum = 0.0; // 합을 저장할 변수 sum을 0으로 초기화
    for (int ii = 0; ii < N; ++ii) {
        sum += R[ii]; // R 벡터의 각 요소를 합산
    }

    // 합계를 출력
    std::cout << "Sum of the result vector: " << sum << std::endl;

    // 동적으로 할당된 행렬 A의 메모리 해제
    for (int i = 0; i < N; ++i) {
        delete[] A[i]; // 각 행에 대한 메모리 해제
    }
    delete[] A; // 행렬 A의 행 포인터 배열 해제

    // 동적으로 할당된 벡터 V와 R의 메모리 해제
    delete[] V; // 벡터 V의 메모리 해제
    delete[] R; // 벡터 R의 메모리 해제

    return 0;
}