#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade) : name("Lucas Sokol")
{
	if (grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

std::string Bureaucrat::getName()
{
	return (this->name);
}

void		Bureaucrat::signForm(Form &obj)
{
	if (obj.isSigned() == 1)
	{
		std::cout << this->name << " signed " << obj.getName() << std::endl;
	}
	else
		std::cout << this->name << " couldn't sign " << obj.getName() << " because " << " grade is too low" << std::endl;
}

int			Bureaucrat::getGrade()
{
	return (this->grade);
}

void		Bureaucrat::gradeIncr()
{
	this->grade -= 1;
	if (grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void		Bureaucrat::gradeDecr()
{
	this->grade += 1;
	if (grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &lucas)
{
	os << lucas.getName() << ", bureaucrat grade " << lucas.getGrade();
	return (os);
}