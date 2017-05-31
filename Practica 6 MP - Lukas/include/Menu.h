#ifndef MENU_H
#define MENU_H

class Menu{
  private:
    char*   titulo;
    char**  opciones;
    int     nopciones;
  public:
    /* Constructor/Destructor */
    Menu();
    ~Menu();

    Menu(const Menu& n);

    /* get/set */
    int getTotal() const;
    void setOpcion(char* opcion);
    void setTitle(char* title);

    /* overload */
    Menu& operator =(const Menu &p);

    /* main */
    void show() const;
    void copy(const Menu& m);
    void deleteOpciones();
};

#endif
