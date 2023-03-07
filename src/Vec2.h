#ifndef _VEC2_H
#define _VEC2_H

class Vec2
{
    private:

    float x,y; 

    public:

    /**
     * @brief Constructeur par defaut de la classe Vec2.
     * 
     */
    Vec2();

    /**
     * @brief Constructeur par copie de la classe Vec2.
     * 
     * @param[in] v 
     */
    Vec2(const Vec2 &v);

    /**
     * @brief Detruit les objets de la classe Vec2.
     * 
     */
    ~Vec2();

    /**
     * @brief operator+ retourne la somme de deux vecteurs. 
     * 
     * @param[in] v2 
     * @return Vec2 
     */

    Vec2 operator+(const Vec2 & v2)const;  

    /**
     * @brief operator- retourne la différence entre deux vecteurs.
     * 
     * @param v2 
     * @return Vec2 
     */
    Vec2 operator-(const Vec2& v2)const;
    
    /**
     * @brief getx récupère la donnée membre x.
     * 
     * @return float& 
     */
    float & getx() const;

    /**
     * @brief setx modifie la valeur de la donnée membre x.
     * 
     * @param x 
     */
    void setx (float x);

    /**
     * @brief getx récupère la donnée membre y.
     * 
     * @return float& 
     */
    float & gety() const;

    /**
     * @brief setx modifie la valeur de la donnée membre y.
     * 
     * @param y 
     */
    void sety (float y);



};

#endif
