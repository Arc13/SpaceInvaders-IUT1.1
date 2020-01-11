#ifndef FAT_BUTTON_H
#define FAT_BUTTON_H

#include "../graph/iminglinjectable.h"
#include "../transition/itransitionable.h"

namespace nsGui
{

class FatButton : public IminGlInjectable, public nsTransition::ITransitionable
{
public:
    FatButton(const Vec2D &position, const Vec2D &size);

    enum {
        TRANSITION_FIRST_RGB,
        TRANSITION_SECOND_RGB,
        TRANSITION_POSITION,
    };

    /**
     * @brief Updates the element
     * @param[in] delta: Time that the previous frame took to render
     * @fn void update(float delta);
     */
    void update(float delta);
    virtual std::unique_ptr<IDrawable> clone() const override;

    virtual void getValues(const int &id, std::vector<float> &values) override;
    virtual void setValues(const int &id, const std::vector<float> &values) override;

protected:
    virtual void draw() override;

private:
    RGBAcolor m_firstColor;
    RGBAcolor m_secondColor;

    Vec2D m_position;
    Vec2D m_size;
};

} // namespace nsGui

#endif // FAT_BUTTON_H
