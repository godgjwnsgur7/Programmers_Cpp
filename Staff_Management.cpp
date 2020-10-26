#include <iostream>
#include <cstring>

using namespace std;

// 직원 관리 프로그램 + 예외 처리

class Employee
{
private:
	char name[100];

public:
	Employee(const char *name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;			 // 순수 가상 함수 (정의x 함수)
	virtual void ShowSalaryInfo() const = 0; // 순수 가상 함수 (정의x 함수)
};

class PermanentWorker : public Employee // 정규직
{
private:
	int salary; // 월 급여
public:
	PermanentWorker(const char *name, int money)
		: Employee(name), salary(money)
	{
	}
	virtual int GetPay() const
	{
		return salary; // 급여 반환
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl
			 << endl;
	}
};

class TemporaryWorker : public Employee // 임시직
{
private:
	int workTime;	// 이 달에 일한 시간의 합계
	int payPerHour; // 시간당 급여
public:
	TemporaryWorker(const char *name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{
	}
	void AddWorkTime(int time) // 일한 시간의 추가
	{
		workTime += time;
	}
	virtual int GetPay() const // 이 달의 급여
	{
		return workTime * payPerHour;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl
			 << endl;
	}
};

class SalesWorker : public PermanentWorker // 영업직
{
private:
	int salesResult;   // 월 판매실적
	double bonusRatio; // 상여금 비율
public:
	SalesWorker(const char *name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{
	}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	virtual int GetPay() const
	{
		return PermanentWorker::GetPay() // PermanentWorker의 GetPay 함수 호출
			   + (int)(salesResult * bonusRatio);
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl
			 << endl; // SalesWorker의 GetPay 함수 호출
	}
};

class ForeignSalesWorker : public SalesWorker
{
	const int riskLevel;

public:
	ForeignSalesWorker(const char *name, int money, double ratio, int risk)
		: SalesWorker(name, money, ratio), riskLevel(risk) {}
	int GetRiskPay() const
	{
		return SalesWorker::GetPay() * (riskLevel / 100.0);
	}
	virtual int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl
			 << endl;
	}
};

class EmployeeHandler
{
private:
	Employee *empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0) // empNum값 초기화
	{
	}
	void AddEmployee(Employee *emp) // 직원 정보의 등록
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const // 모든 직원의 이번 달 급여정보 출력
	{

		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const // 이번 달 급여의 총액 출력
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

namespace RISK_LEVEL
{
	enum
	{
		RISK_A = 30,
		RISK_B = 20,
		RISK_C = 10
	};
};

int main(void)
{
	EmployeeHandler handler;

	ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller1);

	ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller2);

	ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller3);

	// 이번 달에 지불해야 할 급여의 정보들을 출력
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총액
	handler.ShowTotalSalary();

	return 0;
}