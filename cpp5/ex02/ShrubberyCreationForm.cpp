#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreation", 145, 137)
{
	this->target = target;
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << STOP << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->target = obj.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == 0)
	{
		std::cout << "This form isnt signed." << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	std::ifstream file;
	std::string newfile;
	newfile = this->target;
	newfile += "_shrubbery";
	std::ofstream outfile(newfile);

	file.open(newfile);
	if (file.is_open() == 0)
	{
		std::cout << "Cannot create file." << std::endl;
		return ;
	}
	outfile << "          &&& &&  & &&" << std::endl;
	outfile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	outfile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	outfile << "   &() &\\/&|()|/&\\/ \'%\" & ()" << std::endl;
	outfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	outfile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	outfile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	outfile << "     &&     \\|||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "       , -=-~  .-^- _" << std::endl;
	file.close();
	std::cout << executor.getName() << " well executed " << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form(obj)
{
	*this = obj;
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << STOP << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << STOP << std::endl;
}