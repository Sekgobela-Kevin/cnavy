typedef char char_type;
/**
 * @brief computes what character represent using other means including asking os.
 * CLass constains basic implemetations of getting data about character using <cctype>.
 * All methods begins with compute* to show that they perfom calculations.
 * 
 */
class Character_Compute{
    public:
        /**
         * @brief computes if character is ASCII
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsASCII(char_type input_char);
        /**
         * @brief computes if character is alpha numeric
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsAlnum(char_type input_char);

        /**
         * @brief computes if character is alphabetic
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsAlpha(char_type input_char);

        /**
         * @brief computes if character is blank character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsBlank(char_type input_char);

        /**
         * @brief computes if character control character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsCtrl(char_type input_char);

        /**
         * @brief computes if character is digit
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsDigit(char_type input_char);

        /**
         * @brief computes if character is in lowercase
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsLower(char_type input_char);

        /**
         * @brief computes if character is printable
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsPrint(char_type input_char);

        /**
         * @brief computes if character is punctuation character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsPunct(char_type input_char);

        /**
         * @brief computes if character is space character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsSpace(char_type input_char);

        /**
         * @brief computes if character is uppercase
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsUpper(char_type input_char);

        /**
         * @brief computes if character is represented is hexadecimal
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsXdigit(char_type input_char);

        /**
         * @brief computes if character is graphical character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        static bool computeIsGraph(char_type input_char);


       
        /**
         * @brief computes lowercase version of character
         * 
         * @param character 
         * @return char_type 
         */
        static char_type computeToLower(char_type character);

        /**
         * @brief computes uppercase version of character
         * 
         * @param character 
         * @return char_type 
         */
        static char_type computeToUpper(char_type character);


};

/**
 * @brief provide access to data about character and the data can be changed such 
 * as making non-space character be space character
 * 
 */
class Character{
    protected:
        /**
         * @brief containes the character represented by Character object
         * 
         */
        char_type current_char;

        /**
         * @brief update attributes for character in case character was changed
         * @param input_char
         */
        virtual void updateAttrs(char_type input_char);

    public:
        /**
         * @brief Construct a new Character object
         * 
         * @param input_char 
         */
        Character(char_type input_char);
        /**
         * @brief checks if character is alpha numeric
         * 
         * @return true 
         * @return false 
         */
        bool isalnum();
        /**
         * @brief sets character as alpha numeric
         * @param value boolean value
         * 
         */
        void isalnum(bool value);

        /**
         * @brief checks if character is alphabetic
         * 
         * @return true 
         * @return false 
         */
        bool isalpha();

        /**
         * @brief checks if character is used to seperate words(e.g default: space and hrizontal tab)
         * 
         * @return true 
         * @return false 
         */
        bool isblank();

        /**
         * @brief checks if character is control character
         * 
         * @return true 
         * @return false 
         */
        bool iscntrl();

        /**
         * @brief checks if character is digit
         * 
         * @return true 
         * @return false 
         */
        bool isdigit();

        /**
         * @brief checks if character is in lowercase
         * 
         * @return true 
         * @return false 
         */
        bool islower();

        /**
         * @brief checks if character is printable
         * 
         * @return true 
         * @return false 
         */
        bool isprint();

        /**
         * @brief checks if character is punctuation
         * 
         * @return true 
         * @return false 
         */
        bool ispunct();

        /**
         * @brief checks if character is white space
         * 
         * @return true 
         * @return false 
         */
        bool isspace();

        /**
         * @brief checks if charcter is in uppercase
         * 
         * @return true 
         * @return false 
         */
        bool isupper();

        /**
         * @brief checks if chraracter is represented as hexadecimal digit(0-9, a-f, A-F)
         * 
         * @return true 
         * @return false 
         */
        bool isxdigit();

        /**
         * @brief checks character is graphical(Alphanumeric and Punctuation characters)
         * 
         * @return true 
         * @return false 
         */
        bool isgraph();

        /**
         * @brief checks if character is part ASCII character sets
         * 
         * @return true 
         * @return false 
         */
        bool isASCII();

        /**
         * @brief converts stored character to lowercase
         * 
         * @return int 
         */
        char_type tolower();

        /**
         * @brief converts stored character to uppercase
         * 
         */
        char_type toupper();

        /**
         * @brief Sets attractribute containing the character
         * 
         * @param input_char 
         * @param update_atrr specifies of object attributes be changed to match new character
         */
        void setCurrentChar(char_type input_char, bool update_atrr=false);
        /**
         * @brief retrieves underlying character
         * 
         * @return char_type 
         */
        char_type getCurrentChar();
};
