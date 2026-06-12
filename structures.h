struct GameState {
    // Текущее состояние поля (1 - живая, 0 - мёртвая)
    unsigned char current[HEIGHT][WIDTH];

    // Буфер для следующего поколения (для одновременного обновления)
    unsigned char next[HEIGHT][WIDTH];

    // Скорость смены поколений (задержка в миллисекундах)
    int delay_ms;

    // Флаги состояния игры
    int is_running;  // 1 - игра активна, 0 - завершена
    int is_stable;   // 1 - достигнута стабильная конфигурация
    int population;  // Текущее количество живых клеток

    // Статистика для определения стабильности
    unsigned long generation;              // Номер текущего поколения
    unsigned long last_population_change;  // Когда последний раз менялась популяция
};

// Вспомогательная структура для координат
struct Cell {
    int x;  // от 0 до WIDTH-1
    int y;  // от 0 до HEIGHT-1
};