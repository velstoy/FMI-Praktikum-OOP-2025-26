#include<print>

constexpr unsigned int MAX_ID = 99999;
constexpr unsigned int MIN_ID = 10000;

enum class Major
{
	Bachelor,
	Master,
	PhD,
	Default
};

struct Teacher
{
	public:
		bool initializeTeacher(unsigned int ID, Major major, unsigned int failedStudentCount)
		{
			if (ID > MAX_ID || ID < MIN_ID)
			{
				std::println("Failed to initialize! Invalid Teacher ID - ID must always be 5 characters long!");
				return false;
			}
		
			switch (major)
			{
				case Major::Bachelor:
				case Major::Master:
				case Major::PhD:
					break;
				default:
					std::println("Failed to initialize! Invalid Major - Major must be either Bachelor, Master or PhD");
					return false;
			}

			this->ID = ID;
			this->major = major;
			this->failedStudentCount = failedStudentCount;

			return true;
		}

		void print()
		{
			std::println("ID: {}", ID);
			std::print("Major: ");
			switch (major)
			{
				case Major::Bachelor:
					std::println("Bachelor");
					break;
				case Major::Master:
					std::println("Master");
					break;
				case Major::PhD:
					std::println("PhD");
					break;
				default:
					std::println("None");
					break;
			}

			std::println("Failed Student Count: {}", failedStudentCount);
		}
		

	private:
		unsigned int ID = 0;
		Major major = Major::Default;
		unsigned int failedStudentCount = 0;
};

int main()
{
	Teacher teacher;

	if (teacher.initializeTeacher(19787, Major::PhD, 89))
	{
		teacher.print();
	}

	return 0;
}