#include "character.hpp"
#include  <string>

/**
 * @brief provide basic implementation for Line_Characters Class methods.
 * All methods begins with compute* to show that they perfom calculations.
 * 
 */
class Compute_Line_Character{
    protected:
        /**
         * @brief computes if character is newline character
         * 
         * @param character 
         * @return true 
         * @return false 
         */
        bool computeIsNewLineChar(char_type character);
        /**
         * @brief computes if character is question mark
         * 
         * @param character 
         * @return true 
         * @return false 
         */
        bool computeIsQuestChar(char_type character);

};

/**
 * @brief class for representing character at text line level.
 * Adds more methods for working with characters at line level also keeping methods
 * from Characters Class
 * 
 */
class Line_Character : public Character, protected Compute_Line_Character{
    protected:
        bool is_new_line_char;
        bool is_quest_char;
        bool is_at_line_end;
        bool is_at_line_beg;
        bool is_isolated;
        /**
         * @brief update attributes for character in case character was changed
         * @param input_char
         */
        virtual void updateAttrs(char_type input_char);

    public:
        /**
         * @brief Construct a new Line_Character object
         * 
         * @param input_char 
         */
        Line_Character(char_type input_char);
        /**
         * @brief checks if character represent new line character
         * 
         * @param line_text
         * @return true 
         * @return false 
         */
        bool isNewLineChar();
        /**
         * @brief set character as newline character
         * 
         * @param value 
         */
        void isNewLineChar(bool value);

        /**
         * @brief checks if character is at end of line
         * 
         * @return true 
         * @return false 
         */
        bool isAtLineEnd();
        /**
         * @brief set character as located at end of line
         * 
         * @param value 
         */
        void isAtLineEnd(bool value);

        /**
         * @brief checks if character is at beggining of line
         * 
         * @return true 
         * @return false 
         */
        bool isAtLineBeg();
        /**
         * @brief set character as located at beggining of line
         * 
         * @param value 
         */
        void isAtLineBeg(bool value);

        /**
         * @brief checks if character is question mark(you never wanna use it)
         * 
         * @return true 
         * @return false 
         */
        bool isQuestChar();
        /**
         * @brief set character as question mark
         * 
         * @param value 
         */
        void isQuestChar(bool value);

        /**
         * @brief checks if character is isolated(not part of word e.g I)
         * 
         * @return true 
         * @return false 
         */
        bool isIsolated();
        /**
         * @brief sets character as being isolated(e.g I, a, etc)
         * 
         * @param value 
         */
        void isIsolated(bool value);
};