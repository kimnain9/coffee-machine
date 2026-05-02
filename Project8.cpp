#include <iostream>
using namespace std;

/*
    CoffeeMachine 클래스
    - 커피머신 하나를 객체로 표현한 클래스이다.
    - 커피머신의 상태는 멤버 변수로 저장하고,
      커피머신의 기능은 멤버 함수로 구현한다.
*/
class CoffeeMachine {
private:
    /*
        private 영역
        - 커피머신 내부에서 관리되어야 하는 상태값을 저장한다.
        - 외부에서 직접 값을 바꾸면 재료가 음수가 되는 등
          잘못된 상태가 생길 수 있으므로 private으로 보호한다.
    */
    int water;        // 물의 양을 저장한다. 단위는 ml이다.
    int coffee;       // 커피 가루의 양을 저장한다. 단위는 g이다.
    int milk;         // 우유의 양을 저장한다. 단위는 ml이다.
    int cup;          // 남아 있는 컵의 개수를 저장한다.
    int totalCount;   // 지금까지 만든 커피의 총 잔 수를 저장한다.
    int cleanCount;   // 커피머신을 청소한 횟수를 저장한다.
    bool power;       // 전원 상태를 저장한다. true는 켜짐, false는 꺼짐을 의미한다.

public:
    /*
        public 영역
        - 사용자가 직접 호출할 수 있는 기능을 모아 둔다.
        - 내부 변수에 직접 접근하지 않고,
          정해진 함수를 통해 커피머신을 사용하도록 한다.
    */
    CoffeeMachine();                             // 기본 생성자
    CoffeeMachine(int w, int c, int m, int cp);  // 초기 재료값을 직접 설정하는 생성자
    ~CoffeeMachine();                            // 소멸자

    void powerOn();        // 전원 켜기
    void powerOff();       // 전원 끄기
    void showStatus();     // 현재 재료와 전원 상태 확인
    void showRecipe();     // 커피별 필요한 재료 확인

    void makeAmericano();  // 아메리카노 만들기
    void makeLatte();      // 라떼 만들기
    void makeEspresso();   // 에스프레소 만들기

    void fillWater(int amount);   // 물 보충
    void fillCoffee(int amount);  // 커피 가루 보충
    void fillMilk(int amount);    // 우유 보충
    void fillCup(int amount);     // 컵 보충

    void cleanMachine();    // 커피머신 청소
    void showTotalCount();  // 총 제조 잔 수 확인
    void runMenu();         // 메뉴 실행
};

/*
    기본 생성자
    - 사용자가 재료값을 직접 입력하지 않고 시작할 때 호출된다.
    - 커피머신이 바로 사용할 수 있는 기본 재료값으로 초기화한다.
*/
CoffeeMachine::CoffeeMachine() {
    water = 700;
    coffee = 150;
    milk = 300;
    cup = 5;
    totalCount = 0;
    cleanCount = 0;
    power = false;  // 처음에는 사용자가 직접 전원을 켜도록 꺼진 상태로 시작한다.

    cout << "--- 커피머신이 기본 설정으로 준비되었습니다. ---" << endl;
}

/*
    매개변수가 있는 생성자
    - 사용자가 직접 입력한 초기 재료값으로 커피머신을 시작할 때 호출된다.
    - w, c, m, cp는 각각 물, 커피 가루, 우유, 컵의 초기값이다.
*/
CoffeeMachine::CoffeeMachine(int w, int c, int m, int cp) {
    water = w;
    coffee = c;
    milk = m;
    cup = cp;
    totalCount = 0;
    cleanCount = 0;
    power = false;

    cout << "--- 설정한 재료로 커피머신이 준비되었습니다. ---" << endl;
}

/*
    소멸자
    - 커피머신 객체가 사라질 때 자동으로 호출된다.
    - 이 코드에서는 객체가 소멸되는 시점을 확인하기 위해 종료 문장을 출력한다.
*/
CoffeeMachine::~CoffeeMachine() {
    cout << "--- 커피머신 사용을 종료합니다. ---" << endl;
}

void CoffeeMachine::powerOn() {
    /*
        이미 전원이 켜져 있다면 다시 켤 필요가 없으므로 안내 문장만 출력한다.
        전원이 꺼져 있을 때만 power 값을 true로 변경한다.
    */
    if (power == true) {
        cout << "이미 전원이 켜져 있습니다." << endl;
    }
    else {
        power = true;
        cout << "커피머신 전원을 켰습니다." << endl;
    }
}

void CoffeeMachine::powerOff() {
    /*
        이미 전원이 꺼져 있다면 다시 끌 필요가 없으므로 안내 문장만 출력한다.
        전원이 켜져 있을 때만 power 값을 false로 변경한다.
    */
    if (power == false) {
        cout << "이미 전원이 꺼져 있습니다." << endl;
    }
    else {
        power = false;
        cout << "커피머신 전원을 껐습니다." << endl;
    }
}

void CoffeeMachine::showStatus() {
    /*
        현재 커피머신의 상태를 한 번에 확인하는 함수이다.
        재료의 남은 양, 제조 횟수, 청소 횟수, 전원 상태를 출력한다.
    */
    cout << endl;
    cout << "===== 커피머신 현재 상태 =====" << endl;
    cout << "물: " << water << "ml" << endl;
    cout << "커피 가루: " << coffee << "g" << endl;
    cout << "우유: " << milk << "ml" << endl;
    cout << "컵: " << cup << "개" << endl;
    cout << "총 제조 잔 수: " << totalCount << "잔" << endl;
    cout << "청소 횟수: " << cleanCount << "회" << endl;

    if (power == true) {
        cout << "전원 상태: 켜짐" << endl;
    }
    else {
        cout << "전원 상태: 꺼짐" << endl;
    }
}

void CoffeeMachine::showRecipe() {
    /*
        커피를 만들기 전에 필요한 재료를 확인할 수 있도록 레시피를 출력한다.
        각 커피는 필요한 물, 커피 가루, 우유, 컵의 양이 다르다.
    */
    cout << endl;
    cout << "===== 커피 레시피 =====" << endl;
    cout << "아메리카노: 물 200ml, 커피 가루 20g, 컵 1개" << endl;
    cout << "라떼: 물 150ml, 커피 가루 20g, 우유 100ml, 컵 1개" << endl;
    cout << "에스프레소: 물 50ml, 커피 가루 30g, 컵 1개" << endl;
}

void CoffeeMachine::makeAmericano() {
    /*
        아메리카노 제조 조건
        - 전원이 켜져 있어야 한다.
        - 물 200ml, 커피 가루 20g, 컵 1개가 필요하다.
        - 조건을 만족하지 못하면 return으로 함수를 종료한다.
    */
    if (power == false) {
        cout << "전원이 꺼져 있어 아메리카노를 만들 수 없습니다." << endl;
        return;
    }

    if (water < 200) {
        cout << "물이 부족하여 아메리카노를 만들 수 없습니다." << endl;
        return;
    }

    if (coffee < 20) {
        cout << "커피 가루가 부족하여 아메리카노를 만들 수 없습니다." << endl;
        return;
    }

    if (cup < 1) {
        cout << "컵이 부족하여 아메리카노를 만들 수 없습니다." << endl;
        return;
    }

    water = water - 200;
    coffee = coffee - 20;
    cup = cup - 1;
    totalCount = totalCount + 1;

    cout << "아메리카노가 완성되었습니다." << endl;
}

void CoffeeMachine::makeLatte() {
    /*
        라떼 제조 조건
        - 전원이 켜져 있어야 한다.
        - 물 150ml, 커피 가루 20g, 우유 100ml, 컵 1개가 필요하다.
    */
    if (power == false) {
        cout << "전원이 꺼져 있어 라떼를 만들 수 없습니다." << endl;
        return;
    }

    if (water < 150) {
        cout << "물이 부족하여 라떼를 만들 수 없습니다." << endl;
        return;
    }

    if (coffee < 20) {
        cout << "커피 가루가 부족하여 라떼를 만들 수 없습니다." << endl;
        return;
    }

    if (milk < 100) {
        cout << "우유가 부족하여 라떼를 만들 수 없습니다." << endl;
        return;
    }

    if (cup < 1) {
        cout << "컵이 부족하여 라떼를 만들 수 없습니다." << endl;
        return;
    }

    water = water - 150;
    coffee = coffee - 20;
    milk = milk - 100;
    cup = cup - 1;
    totalCount = totalCount + 1;

    cout << "라떼가 완성되었습니다." << endl;
}

void CoffeeMachine::makeEspresso() {
    /*
        에스프레소 제조 조건
        - 전원이 켜져 있어야 한다.
        - 물 50ml, 커피 가루 30g, 컵 1개가 필요하다.
        - 다른 커피보다 물은 적게 쓰고 커피 가루는 더 많이 사용한다.
    */
    if (power == false) {
        cout << "전원이 꺼져 있어 에스프레소를 만들 수 없습니다." << endl;
        return;
    }

    if (water < 50) {
        cout << "물이 부족하여 에스프레소를 만들 수 없습니다." << endl;
        return;
    }

    if (coffee < 30) {
        cout << "커피 가루가 부족하여 에스프레소를 만들 수 없습니다." << endl;
        return;
    }

    if (cup < 1) {
        cout << "컵이 부족하여 에스프레소를 만들 수 없습니다." << endl;
        return;
    }

    water = water - 50;
    coffee = coffee - 30;
    cup = cup - 1;
    totalCount = totalCount + 1;

    cout << "에스프레소가 완성되었습니다." << endl;
}

void CoffeeMachine::fillWater(int amount) {
    if (amount <= 0) {
        cout << "물을 채우려면 0보다 큰 값을 입력해야 합니다." << endl;
        return;
    }

    water = water + amount;
    cout << "물을 " << amount << "ml 채웠습니다." << endl;
}

void CoffeeMachine::fillCoffee(int amount) {
    if (amount <= 0) {
        cout << "커피 가루를 채우려면 0보다 큰 값을 입력해야 합니다." << endl;
        return;
    }

    coffee = coffee + amount;
    cout << "커피 가루를 " << amount << "g 채웠습니다." << endl;
}

void CoffeeMachine::fillMilk(int amount) {
    if (amount <= 0) {
        cout << "우유를 채우려면 0보다 큰 값을 입력해야 합니다." << endl;
        return;
    }

    milk = milk + amount;
    cout << "우유를 " << amount << "ml 채웠습니다." << endl;
}

void CoffeeMachine::fillCup(int amount) {
    if (amount <= 0) {
        cout << "컵을 채우려면 0보다 큰 값을 입력해야 합니다." << endl;
        return;
    }

    cup = cup + amount;
    cout << "컵을 " << amount << "개 채웠습니다." << endl;
}

void CoffeeMachine::cleanMachine() {
    if (power == false) {
        cout << "전원이 꺼져 있어 청소 기능을 사용할 수 없습니다." << endl;
        return;
    }

    cleanCount = cleanCount + 1;

    cout << "커피머신 내부 청소를 완료했습니다." << endl;
    cout << "현재까지 청소한 횟수는 " << cleanCount << "회입니다." << endl;
}

void CoffeeMachine::showTotalCount() {
    cout << "현재까지 만든 커피는 총 " << totalCount << "잔입니다." << endl;
}

bool checkInput() {
    if (cin.fail()) {
        cout << "올바른 입력이 아닙니다. 숫자를 입력하세요." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    cin.ignore(10000, '\n');
    return true;
}

void CoffeeMachine::runMenu() {
    int menu;
    int amount;

    while (true) {
        cout << endl;
        cout << "========== 커피머신 메뉴 ==========" << endl;
        cout << "1. 전원 켜기" << endl;
        cout << "2. 전원 끄기" << endl;
        cout << "3. 아메리카노 만들기" << endl;
        cout << "4. 라떼 만들기" << endl;
        cout << "5. 에스프레소 만들기" << endl;
        cout << "6. 물 채우기" << endl;
        cout << "7. 커피 가루 채우기" << endl;
        cout << "8. 우유 채우기" << endl;
        cout << "9. 컵 채우기" << endl;
        cout << "10. 현재 상태 확인" << endl;
        cout << "11. 커피머신 청소" << endl;
        cout << "12. 총 제조 잔 수 확인" << endl;
        cout << "13. 커피 레시피 확인" << endl;
        cout << "0. 프로그램 종료" << endl;
        cout << "메뉴를 선택하세요: ";
        cin >> menu;

        if (checkInput() == false) {
            continue;
        }

        if (menu == 1) {
            powerOn();
        }
        else if (menu == 2) {
            powerOff();
        }
        else if (menu == 3) {
            makeAmericano();
        }
        else if (menu == 4) {
            makeLatte();
        }
        else if (menu == 5) {
            makeEspresso();
        }
        else if (menu == 6) {
            cout << "채울 물의 양을 입력하세요: ";
            cin >> amount;

            if (checkInput() == false) {
                continue;
            }

            fillWater(amount);
        }
        else if (menu == 7) {
            cout << "채울 커피 가루의 양을 입력하세요: ";
            cin >> amount;

            if (checkInput() == false) {
                continue;
            }

            fillCoffee(amount);
        }
        else if (menu == 8) {
            cout << "채울 우유의 양을 입력하세요: ";
            cin >> amount;

            if (checkInput() == false) {
                continue;
            }

            fillMilk(amount);
        }
        else if (menu == 9) {
            cout << "채울 컵의 개수를 입력하세요: ";
            cin >> amount;

            if (checkInput() == false) {
                continue;
            }

            fillCup(amount);
        }
        else if (menu == 10) {
            showStatus();
        }
        else if (menu == 11) {
            cleanMachine();
        }
        else if (menu == 12) {
            showTotalCount();
        }
        else if (menu == 13) {
            showRecipe();
        }
        else if (menu == 0) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "올바른 메뉴 번호가 아닙니다. 다시 선택하세요." << endl;
        }
    }
}

int main() {
    int startMenu;
    int w, c, m, cp;

    while (true) {
        cout << "========== 커피머신 시작 설정 ==========" << endl;
        cout << "1. 기본 설정으로 시작" << endl;
        cout << "2. 재료를 직접 설정해서 시작" << endl;
        cout << "선택하세요: ";
        cin >> startMenu;

        if (checkInput() == false) {
            continue;
        }

        if (startMenu == 1) {
            CoffeeMachine machine;
            machine.runMenu();
            break;
        }
        else if (startMenu == 2) {
            cout << "초기 물의 양을 입력하세요: ";
            cin >> w;

            if (checkInput() == false) {
                continue;
            }

            if (w <= 0) {
                cout << "초기 물의 양은 0보다 큰 값이어야 합니다." << endl;
                continue;
            }

            cout << "초기 커피 가루의 양을 입력하세요: ";
            cin >> c;

            if (checkInput() == false) {
                continue;
            }

            if (c <= 0) {
                cout << "초기 커피 가루의 양은 0보다 큰 값이어야 합니다." << endl;
                continue;
            }

            cout << "초기 우유의 양을 입력하세요: ";
            cin >> m;

            if (checkInput() == false) {
                continue;
            }

            if (m <= 0) {
                cout << "초기 우유의 양은 0보다 큰 값이어야 합니다." << endl;
                continue;
            }

            cout << "초기 컵의 개수를 입력하세요: ";
            cin >> cp;

            if (checkInput() == false) {
                continue;
            }

            if (cp <= 0) {
                cout << "초기 컵의 개수는 0보다 큰 값이어야 합니다." << endl;
                continue;
            }

            CoffeeMachine machine(w, c, m, cp);
            machine.runMenu();
            break;
        }
        else {
            cout << "올바른 메뉴 번호가 아닙니다. 다시 선택하세요." << endl;
        }
    }

    return 0;
}