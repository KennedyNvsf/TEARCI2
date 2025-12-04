


enum ESTADO {
    TURNING_OFF,
    TURNED_OFF,
    TURNING_ON,
    TURNED_ON
};

ESTADO estado = TURNED_OFF;

void setup()
{

}

void loop()
{
    switch(estado)
    {
        case TURNING_OFF:
            // Do something
            estado = TURNED_OFF;
            break;
        case TURNED_OFF:
            // Do something
            estado = TURNING_ON;
            break;
        case TURNING_ON:
            // Do something
            estado = TURNED_ON;
            break;
        case TURNED_ON:
            // Do something
            estado = TURNING_OFF;
            break;
    }
}