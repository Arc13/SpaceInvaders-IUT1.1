#ifndef DISPLAY_SPRITE_H
#define DISPLAY_SPRITE_H

#include <cstdint>

#include "../graph/iminglinjectable.h"

namespace nsGui {

class Sprite : public IminGlInjectable
{
public:
    /**
     * @brief Constructeur pour la classe Sprite, charge les données depuis un fichier
     * @param[in] filename : Chemin d'accès vers le fichier image
     * @param[in] position : Position du sprite
     * @fn Sprite(const std::string &filename, const Vec2D &position);
     */
    Sprite(const std::string &filename, const Vec2D &position = Vec2D());

    /**
     * @brief Constructeur pour la classe Sprite, copie les données depuis un vecteur de pixels
     * @param[in] pixelData : Vecteur contenant des données sur les pixels
     * @param[in] position : Position du sprite
     * @fn Sprite(const std::string &filename, const Vec2D &position);
     */
    Sprite(const std::vector<RGBAcolor> &pixelData, const uint32_t &rowSize, const Vec2D &position = Vec2D());

    void update(float delta);
    virtual std::unique_ptr<IDrawable> clone() const override;
    virtual void draw(MinGL &window) override;

    const uint32_t& getRowSize() const;
    const std::vector<RGBAcolor>& getPixelData() const;

private:
    struct FileBegin {
        uint16_t magic;
        uint32_t headmagic;
        uint16_t fileVersion;
        uint32_t pixelCount;
        uint32_t rowSize;
        uint32_t datamagic;
    } __attribute__((packed));

    Vec2D m_position;

    uint32_t m_rowSize;
    std::vector<RGBAcolor> m_pixelData;
};

}

#endif // DISPLAY_SPRITE_H
