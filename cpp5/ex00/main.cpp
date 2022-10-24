#include "Bureaucrat.hpp"
#include "color.hpp"

void aff_err(std::string str, std::exception const &except) {
    std::cerr << RED << BOLD << str << ": " << STOP << LRED << except.what() << STOP << std::endl;
}

void test(std::string name, int grade, int gradeup, int gradedown) {
    
    Bureaucrat *bur = NULL;
    
    try {
        bur = new Bureaucrat(name, grade);
    }
    catch (std::exception const &except) {
        aff_err("Cannot create Bureaucrat", except);
        return ;
    }
    
    try {
        for (int i = 0; i < gradedown; i++) {
            bur->gradeDecr();
        }
    }
    catch (std::exception const &except) {
        aff_err("Cannot grade down Bureaucrat", except);
    }
    
    try {
        for (int i = 0; i < gradeup; i++) {
            bur->gradeIncr();
        }
    }
    catch (std::exception const &except) {
        aff_err("Cannot grade up Bureaucrat", except);
    }
    delete bur;
}

int main() 
{
    std::cout << LGREEN << "Test 1 : everything is ok" << STOP << std::endl;
    test("boba", 100, 3, 10);
    std::cout << std::endl << LGREEN << "Test 2 : Too much grade up" << STOP << std::endl;
    test("bobb", 100, 1000, 10);
    std::cout << std::endl << LGREEN << "Test 3 : Too much grade down" << STOP << std::endl;
    test("bobc", 100, 10, 1000);
    std::cout << std::endl << LGREEN << "Test 4 : Too much grade up and grade down" << STOP << std::endl;
    test("bobd", 100, 500, 1000);
    std::cout << std::endl << LGREEN << "Test 5 : Init with too high grade" << STOP << std::endl;
    test("bobe", -42, 10, 10);
    std::cout << std::endl << LGREEN << "Test 6 : Init with too low grade" << STOP << std::endl;
    test("bobf", 242, 10, 10);
    std::cout << std::endl;
    
    Bureaucrat rix("Rix", 42);
    Bureaucrat rix_bis(rix);
    Bureaucrat rax("Rax", 21);
    rax = rix;
    std::cout << ORANGE << rax << STOP << std::endl;
	Bureaucrat rox(rix);
	std::cout << ORANGE << rox << STOP << std::endl;
}