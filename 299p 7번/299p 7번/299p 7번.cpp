#include <iostream>
using namespace std;

// 학생 클래스 
class Student
{
protected:
	string name;
	int com_score;
public:
// 학생 생성자
	Student(string name, int com_score)
	{
		this->name = name;
		this->com_score = com_score;
	}
// 이름 입력 
	string getName() {
		cout << "학생의 이름" << name << "입니다." << endl;
		return name;
	}
// 컴퓨터 성적 변경하기 
	void modifycom_score(int score)
	{
		com_score = score;
		return;
	}
// 평균 알아내기 
	virtual double avg()
	{
		double avg = com_score;
		return avg;
	}
};

// 이과 클래스 

class mathStudent : public Student
{
private:
	int sci_score;
public:
	mathStudent(string name, int com_score, int sci_score) : Student(name, com_score)
	{
		this->sci_score = sci_score;
	}

	double avg()
	{
		double avg = (sci_score + com_score) / 2;
		return avg;
	}

	void modifysci_score(int score)
	{
		sci_score = score;
	}
};

class koreaStudent : public Student
{
private: 
	int soc_score;
public:
	koreaStudent(string name, int com_score, int soc_score) : Student(name, com_score)
	{
		this->soc_score = soc_score;
	}

	double avg()
	{
		double avg = (soc_score + com_score) / 2;
		return avg;
	}
	
	void modifysoc_score(int score)
	{
		soc_score = score;
	}
};

//1학년 클래스 
class firstStudent : public Student {
	firstStudent(string name, int com_score) : Student(name, com_score)
	{}
};