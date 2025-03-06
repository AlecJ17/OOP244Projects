/*
     *****************************************************************************
                   <Workshop - #6 (Lab)>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : March 06,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca{

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{'\0'};
		Email() {};
		Email& operator=(const Email&);
		bool load(std::ifstream& in);
		~Email();
		// Prohibit the copy constructor for this class: 
        Email(const Email&) = delete;
		// Make the EmailFile class a "friend" of the Email class
        friend class EmailFile;
	};

	
	class EmailFile
	{
		Email* m_emailLines{ nullptr };
		char* m_filename{};
		int m_noOfEmails{ 0 }; 
		void setFilename(const char* filename);
		void setEmpty();
		bool setNoOfEmails();
        void loadEmails();
		
	public:
        // Constructors
        EmailFile();
        EmailFile(const char* filename);

        // Rule of three
        EmailFile(const EmailFile& other);
        EmailFile& operator=(const EmailFile& other);
        ~EmailFile();
        // Type conversion overloads
        operator bool() const;

        // Public methods
        bool saveToFile(const char* filename) const;
        void fileCat(const EmailFile& obj, const char* name = nullptr);

        std::ostream& view(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}
#endif // !SENECA_EMAILFILE_H
