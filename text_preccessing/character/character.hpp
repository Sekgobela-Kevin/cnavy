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
        bool computeIsASCII(wchar_t input_char);
        /**
         * @brief computes if character is alpha numeric
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsAlnum(wchar_t input_char);

        /**
         * @brief computes if character is alphabetic
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsAlpha(wchar_t input_char);

        /**
         * @brief computes if character is blank character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsBlank(wchar_t input_char);

        /**
         * @brief computes if character control character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsCtrl(wchar_t input_char);

        /**
         * @brief computes if character is digit
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsDigit(wchar_t input_char);

        /**
         * @brief computes if character is in lowercase
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsLower(wchar_t input_char);

        /**
         * @brief computes if character is printable
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsPrint(wchar_t input_char);

        /**
         * @brief computes if character is punctuation character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsPunct(wchar_t input_char);

        /**
         * @brief computes if character is space character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsSpace(wchar_t input_char);

        /**
         * @brief computes if character is uppercase
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsUpper(wchar_t input_char);

        /**
         * @brief computes if character is represented is hexadecimal
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsXdigit(wchar_t input_char);

        /**
         * @brief computes if character is graphical character
         * 
         * @param input_char 
         * @return true 
         * @return false 
         */
        bool computeIsGraph(wchar_t input_char);


       
        /**
         * @brief computes lowercase version of character
         * 
         * @param character 
         * @return wchar_t 
         */
        wchar_t computeToLower(wchar_t character);

        /**
         * @brief computes uppercase version of character
         * 
         * @param character 
         * @return wchar_t 
         */
        wchar_t computeToUpper(wchar_t character);


};

/**
 * @brief provide access to data about character and the data can be changed such 
 * as making non-space character be space character
 * 
 */
class Character : private Character_Compute{
    protected:
        /**
         * @brief containes the character represented by Character object
         * 
         */
        wchar_t current_char;
        bool is_ASCII;
        bool is_alnum;
        bool is_alpha;
        bool is_blank;
        bool is_cntrl;
        bool is_digit;
        bool is_lower;
        bool is_print;
        bool is_punct;
        bool is_space;
        bool is_upper;
        bool is_xdigit;
        bool is_graph;

        wchar_t lower_char;
        wchar_t upper_char;

        /**
         * @brief update attributes for character in case character was changed
         * @param input_char
         */
        virtual void updateAttrs(wchar_t input_char);

    public:
        /**
         * @brief Construct a new Character object
         * 
         * @param input_char 
         */
        Character(wchar_t input_char);
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
         * @brief sets character as alphabetic
         * 
         * @param value 
         */
        void isalpha(bool value);

        /**
         * @brief checks if character is used to seperate words(e.g default: space and hrizontal tab)
         * 
         * @return true 
         * @return false 
         */
        bool isblank();
        /**
         * @brief set chararacter as blank character
         * 
         * @param value 
         */
        void isblank(bool value);

        /**
         * @brief checks if character is control character
         * 
         * @return true 
         * @return false 
         */
        bool iscntrl();
        /**
         * @brief set character as control character
         * 
         * @param value 
         */
        void iscntrl(bool value);

        /**
         * @brief checks if character is digit
         * 
         * @return true 
         * @return false 
         */
        bool isdigit();
        /**
         * @brief set character as digit
         * 
         * @param value 
         */
        void isdigit(bool value);

        /**
         * @brief checks if character is in lowercase
         * 
         * @return true 
         * @return false 
         */
        bool islower();
        /**
         * @brief set chracter as lowercase
         * 
         * @param value 
         */
        void islower(bool value);

        /**
         * @brief checks if character is printable
         * 
         * @return true 
         * @return false 
         */
        bool isprint();
        /**
         * @brief set chracter as printable
         * 
         * @param value 
         */
        void isprint(bool value);

        /**
         * @brief checks if character is punctuation
         * 
         * @return true 
         * @return false 
         */
        bool ispunct();
        /**
         * @brief set chracter as puctuation character
         * 
         * @param value 
         */
        void ispunct(bool value);

        /**
         * @brief checks if character is white space
         * 
         * @return true 
         * @return false 
         */
        bool isspace();
        /**
         * @brief set chracter as space character
         * 
         * @param value 
         */
        void isspace(bool value);

        /**
         * @brief checks if charcter is in uppercase
         * 
         * @return true 
         * @return false 
         */
        bool isupper();
        /**
         * @brief set chracter as uppercase
         * 
         * @param value 
         */
        void isupper(bool value);

        /**
         * @brief checks if chraracter is represented as hexadecimal digit(0-9, a-f, A-F)
         * 
         * @return true 
         * @return false 
         */
        bool isxdigit();
        /**
         * @brief set chracter as hexadecimal digit
         * 
         * @param value 
         */
        void isxdigit(bool value);

        /**
         * @brief checks character is graphical(Alphanumeric and Punctuation characters)
         * 
         * @return true 
         * @return false 
         */
        bool isgraph();
        /**
         * @brief set chracter as graphical character
         * 
         * @param value 
         */
        void isgraph(bool value);

        /**
         * @brief checks if character is part ASCII character sets
         * 
         * @return true 
         * @return false 
         */
        bool isASCII();
        /**
         * @brief set character as part of ASCII character sets
         * 
         * @param value
         */
        void isASCII(bool value);

        /**
         * @brief converts stored character to lowercase
         * 
         * @return int 
         */
        wchar_t tolower();
        /**
         * @brief set lowercase version of character
         * 
         */
        void tolower(wchar_t character);

        /**
         * @brief converts stored character to uppercase
         * 
         */
        wchar_t toupper();
        /**
         * @brief set uppercase version of character
         * 
         */
        void toupper(wchar_t character);

        /**
         * @brief Sets attractribute containing the character
         * 
         * @param input_char 
         * @param update_atrr specifies of object attributes be changed to match new character
         */
        void setCurrentChar(wchar_t input_char, bool update_atrr=false);
        /**
         * @brief retrieves underlying character
         * 
         * @return wchar_t 
         */
        wchar_t getCurrentChar();
};
