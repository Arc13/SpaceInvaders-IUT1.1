/**
 * @file glut_font.h
 * @brief Utility class to get fonts that Glut provides
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 28 décembre 2019
 */

#ifndef GLUT_FONTS_H
#define GLUT_FONTS_H

class GlutFont
{
public:
    /**
     * @brief GlutFonts : List of all Glut fonts
     */
    enum GlutFonts
    {
        BITMAP_8_BY_13, /**< 8x13 Bitmap font */
        BITMAP_9_BY_15, /**< 9x15 Bitmap font */
        BITMAP_TIMES_ROMAN_10, /**< 10px Times New Roman font */
        BITMAP_TIMES_ROMAN_24, /**< 24px Times New Roman font */
        BITMAP_HELVETICA_10, /**< 10px Helvetica font */
        BITMAP_HELVETICA_12, /**< 12px Helvetica font */
        BITMAP_HELVETICA_18, /**< 18px Helvetica font */
    };

    /**
     * @brief Constructor for the GlutFont class
     * @param[in] font_ : Font represented by this instance
     * @fn GlutFont(const GlutFonts &font_);
     */
    GlutFont(const GlutFonts &font_);

    /**
     * @brief Gets the font identifier to be used with Glut
     * @return A Glut font identifier
     * @fn void *convertForGlut() const;
     */
    void *convertForGlut() const;

private:
    /**
     * @brief font : Font represented by this instance
     */
    GlutFonts m_font;
};

#endif // GLUT_FONTS_H
