/**
 * @file iscreen.h
 * @brief Interface for a screen taking the entire window
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#ifndef ISCREEN_H
#define ISCREEN_H

#include <chrono>
#include <memory>

#include "screen_identifiers.h"

#include "../event/event.hpp"
#include "../graph/idrawable.h"
#include "../graph/mingl.h"
/**
 * @namespace nsScreen
 * @brief Espace de nom pour des écrans
 */
namespace nsScreen {

/**
 * @class IScreen
 * @brief Interface pour un écran, prenant l'entièreté de la fenêtre
 */
class IScreen : public IDrawable
{
public:
    /**
     * @brief Destructeur de la classe IScreen
     * @fn virtual ~IScreen() {}
     */
    virtual ~IScreen() {}

    /**
     * @brief Appelée a chaque entrée utilisateur
     * @param[in] event : L'événement qui vient de se produire
     * @fn virtual void processEvent(const nsEvent::Event &event);
     */
    virtual void processEvent(const nsEvent::Event_t &event) = 0;

    /**
     * @brief Appelée a chaque image pour mettre a jour la logique
     * @param[in] delta : Temps que la dernière image a mis pour faire son rendu
     * @fn virtual void update(const std::chrono::microseconds &delta);
     */
    virtual void update(const std::chrono::microseconds &delta) = 0;

    /**
     * @brief Récupère l'ID du nouvel écran vers lequel basculer
     * @return Une référence const vers m_screenChange
     * @fn ScreenIdentifiers getRequestedScreenChange() const;
     */
    const ScreenIdentifiers& getRequestedScreenChange() const;

protected:
    /**
     * @brief Définit l'ID de l'écran vers lequel basculer
     * @param[in] screenId : L'ID du nouvel écran
     * @fn void requestScreenChange(const ScreenIdentifiers &screenId);
     */
    void requestScreenChange(const ScreenIdentifiers &screenId);

private:
    /**
     * @brief m_screenChange : Ecran vers lequel basculer
     */
    ScreenIdentifiers m_screenChange = ScreenIdentifiers::ID_None;
};

} // namespace nsScreen

#endif // ISCREEN_H
