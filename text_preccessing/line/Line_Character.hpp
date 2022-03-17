#include "character.hpp"
#include  <string>

/**
 * @brief class for representing character at text line level
 * 
 */
class Line_Character : public Character{
    protected:
        bool is_new_line;
        bool is_end_line;
        bool is_beg_line;
        bool is_question;
        bool is_isolated;

    public:
        /**
         * @brief checks if character represent new line
         * 
         * @return true 
         * @return false 
         */
        bool isNewLine();
        /**
         * @brief set character as newline character(you never want to use it)
         * 
         * @param value 
         */
        void isNewLine(bool value);

        /**
         * @brief checks if character is at end of line
         * 
         * @return true 
         * @return false 
         */
        bool isEndLine();
        /**
         * @brief set chracter a located at end of line
         * 
         * @param value 
         */
        void isEndLine(bool value);

        /**
         * @brief checks if character is at beggining of line
         * 
         * @return true 
         * @return false 
         */
        bool isBegLine();
        /**
         * @brief set character located at begining of line
         * 
         * @param value 
         */
        void isBegLine(bool value);

        /**
         * @brief checks if character is question mark
         * 
         * @return true 
         * @return false 
         */
        bool isQuestion();
        /**
         * @brief set character as being question mark(not used)
         * 
         * @param value 
         */
        void isQuestion(bool value);

        /**
         * @brief checks if character is isolated(not part of word e.g I)
         * 
         * @return true 
         * @return false 
         */
        bool isIsolated();
        /**
         * @brief set character as being the only character in word(e.g I, a)
         * 
         * @param value 
         */
        void isIsolated(bool value);
};