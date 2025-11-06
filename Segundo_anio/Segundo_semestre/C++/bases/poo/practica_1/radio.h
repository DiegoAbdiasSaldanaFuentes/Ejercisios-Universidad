#ifndef RADIO_H
#define RADIO_H

class radio{
    private:
        int frecuencia;
        int volumen;
    
        public:
            void inicializar(void);
            void subir_volumen(void);
            void bajar_volumen(void);
            void subir_frecuencia(void);
            void bajar_frecuencia(void);
            void mostrar_volumen(void);
            void mostrar_frecuencia (void);
};

#endif