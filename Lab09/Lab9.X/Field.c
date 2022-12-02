#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BOARD.h"
#include "Field.h"


void FieldInit(Field *own_field, Field * opp_field) {
    
    for ( int a = 0; a < FIELD_ROWS; a = a + 1) {
        for (int b = 0; b < FIELD_COLS; b = b + 1) {
            own_field->grid[a][b] = FIELD_SQUARE_EMPTY;
            opp_field->grid[a][b] = FIELD_SQUARE_UNKNOWN;        
        }
    }
    opp_field->smallBoatLives = FIELD_BOAT_SIZE_SMALL;
    opp_field->mediumBoatLives = FIELD_BOAT_SIZE_MEDIUM;
    opp_field->largeBoatLives = FIELD_BOAT_SIZE_LARGE;
    opp_field->hugeBoatLives = FIELD_BOAT_SIZE_HUGE;
}

SquareStatus FieldGetSquareStatus(const Field *f, uint8_t row, uint8_t col) {
    if (row < FIELD_ROWS) {
        if (col < FIELD_COLS){
            return f->grid[row][col];
        }
    } else {
        return FIELD_SQUARE_INVALID;
    }
    return SUCCESS;
}
SquareStatus FieldSetSquareStatus(Field *f, uint8_t row, uint8_t col, SquareStatus p) {
    
    SquareStatus old = FieldGetSquareStatus(f, row, col);
    
    if (row < FIELD_ROWS) {
        if (col < FIELD_COLS){
            f->grid[row][col] = p;
        }
    }
    return old;
}

uint8_t FieldAddBoat(Field *own_field, uint8_t row, uint8_t col, BoatDirection dir, BoatType boat_type) {
    int small = 0;
    int medium = 0;
    int large = 0;
    int huge = 0;
    BoatSize boat;
    SquareStatus state;
    
    
    if (boat_type == FIELD_BOAT_TYPE_SMALL) {
        boat = FIELD_BOAT_SIZE_SMALL;
        state = FIELD_SQUARE_SMALL_BOAT;
        if (dir == FIELD_DIR_EAST) {
            while (small < boat) {
                if (FieldGetSquareStatus(own_field, row, col+small) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                small = small + 1;   
            }
        } else if (dir == FIELD_DIR_SOUTH) {
            while (small < boat) {
                if (FieldGetSquareStatus(own_field, row+small, col) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                small = small + 1;   
            }
        }
    } else if (boat_type == FIELD_BOAT_TYPE_MEDIUM) {
        boat = FIELD_BOAT_SIZE_MEDIUM;
        state = FIELD_SQUARE_MEDIUM_BOAT;
        if (dir == FIELD_DIR_EAST) {
            while (medium < boat) {
                if (FieldGetSquareStatus(own_field, row, col+medium) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                medium = medium + 1;   
            }
        } else if (dir == FIELD_DIR_SOUTH) {
            while (medium < boat) {
                if (FieldGetSquareStatus(own_field, row+medium, col) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                medium = medium + 1;   
                
            }
        }
    } else if (boat_type == FIELD_BOAT_TYPE_LARGE) {
        boat = FIELD_BOAT_SIZE_LARGE;
        state = FIELD_SQUARE_LARGE_BOAT;
        if (dir == FIELD_DIR_EAST) {
            while (large < boat) {
                if (FieldGetSquareStatus(own_field, row, col+large) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                large = large + 1;   
            }
        } else if (dir == FIELD_DIR_SOUTH) {
            while (large < boat) {
                if (FieldGetSquareStatus(own_field, row+large, col) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                large =large + 1;   
            }
        }
    } else if (boat_type == FIELD_BOAT_TYPE_HUGE) {
        boat = FIELD_BOAT_SIZE_HUGE;
        state = FIELD_SQUARE_HUGE_BOAT;
        if (dir == FIELD_DIR_EAST) {
            while (huge < boat) {
                if (FieldGetSquareStatus(own_field, row, col+huge) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                huge = huge+ 1;   
            }
        } else if (dir == FIELD_DIR_SOUTH) {
            while (huge < boat) {
                if (FieldGetSquareStatus(own_field, row+huge, col) != FIELD_SQUARE_EMPTY) {
                    return STANDARD_ERROR;
                } 
                huge =huge+ 1;   
            }
        }
    }
    huge = 0;
    large= 0;
    medium= 0;
    small= 0;
    if (dir == FIELD_DIR_EAST) {
        if (boat_type == FIELD_BOAT_TYPE_HUGE) {
            own_field->hugeBoatLives = FIELD_BOAT_SIZE_HUGE;
            while (huge < boat) {
                FieldSetSquareStatus(own_field, row, col+huge, state);
                huge =huge+ 1;
            }
        } else if (boat_type == FIELD_BOAT_TYPE_LARGE) {
            own_field->largeBoatLives = FIELD_BOAT_SIZE_LARGE;
            while (large < boat) {
                FieldSetSquareStatus(own_field, row, col+large, state);
                large = large+ 1;
            }
        } else if (boat_type == FIELD_BOAT_TYPE_MEDIUM) {
            own_field->mediumBoatLives = FIELD_BOAT_SIZE_MEDIUM;
            while (medium < boat) {
                FieldSetSquareStatus(own_field, row, col+medium, state);
                medium = medium+ 1;
            }
        } else if (boat_type == FIELD_BOAT_TYPE_SMALL) {
            
            while (small < boat) {
                FieldSetSquareStatus(own_field, row, col+small, state);
                small =small + 1;
            }
        }
    }
    if (dir == FIELD_DIR_SOUTH) {
        if (boat_type == FIELD_BOAT_TYPE_HUGE) {
            own_field->largeBoatLives = FIELD_BOAT_SIZE_LARGE;
            while (huge < boat) {
                FieldSetSquareStatus(own_field, row+huge, col, state);
                huge =huge+ 1;
            }
        } else if (boat_type == FIELD_BOAT_TYPE_LARGE) {
            while (large < boat) {
                FieldSetSquareStatus(own_field, row+large, col, state);
                large =large+ 1;
            }
        } else if (boat_type == FIELD_BOAT_TYPE_MEDIUM) {
            own_field->mediumBoatLives = FIELD_BOAT_SIZE_MEDIUM;
            while (medium < boat) {
                FieldSetSquareStatus(own_field, row+medium, col, state);
                medium =medium+ 1;
            }
        } else if (boat_type == FIELD_BOAT_TYPE_SMALL) {
            while (small < boat) {
                FieldSetSquareStatus(own_field, row+small, col, state);
                small =small+ 1;
            }
        }
    }
    if (boat_type == FIELD_BOAT_TYPE_SMALL) {
        own_field->smallBoatLives = FIELD_BOAT_SIZE_SMALL;
    } else if (boat_type == FIELD_BOAT_TYPE_MEDIUM) {
        own_field->mediumBoatLives = FIELD_BOAT_SIZE_MEDIUM;
    } else if (boat_type == FIELD_BOAT_TYPE_LARGE) {
        own_field->largeBoatLives = FIELD_BOAT_SIZE_LARGE;
    } else if (boat_type == FIELD_BOAT_TYPE_HUGE) {
        own_field->hugeBoatLives = FIELD_BOAT_SIZE_HUGE;
    }
    return SUCCESS;
}

SquareStatus FieldRegisterEnemyAttack(Field *own_field, GuessData *opp_guess) {
    uint8_t x = own_field->grid[opp_guess->row][opp_guess->col];
    
    if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_SMALL_BOAT) {
        if (own_field->smallBoatLives == 1) {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_SMALL_BOAT_SUNK;
            own_field->smallBoatLives -= 1;
        } else {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_HIT;
            own_field->smallBoatLives -= 1;
        }
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_MEDIUM_BOAT) {
        if (own_field->mediumBoatLives == 1) {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_MEDIUM_BOAT_SUNK;
            own_field->mediumBoatLives -= 1;
        } else {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_HIT;
            own_field->mediumBoatLives -= 1;
        }
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_LARGE_BOAT) {
        if (own_field->largeBoatLives == 1) {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_LARGE_BOAT_SUNK;
            own_field->largeBoatLives -= 1;
        } else {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_HIT;
            own_field->largeBoatLives -= 1;
        }
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_HUGE_BOAT) {
        if (own_field->hugeBoatLives == 1) {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_HUGE_BOAT_SUNK;
            own_field->hugeBoatLives -= 1;
        } else {
            own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
            opp_guess->result = RESULT_HIT;
            own_field->hugeBoatLives -= 1;
        }
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_EMPTY) {
        own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_MISS;
        opp_guess->result = RESULT_MISS;
    } else {
        own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_MISS;
        opp_guess->result = RESULT_MISS;
    }
    return x;
}

SquareStatus FieldUpdateKnowledge(Field *opp_field, const GuessData *own_guess) {
    uint8_t y = opp_field->grid[own_guess->row][own_guess->col];
    
    if (own_guess->result == RESULT_MISS) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_EMPTY;
    } else if (own_guess->result == RESULT_HIT) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
    } else if (own_guess->result == RESULT_HUGE_BOAT_SUNK) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
        opp_field->smallBoatLives = 0;
    } else if (own_guess->result == RESULT_LARGE_BOAT_SUNK) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
        opp_field->mediumBoatLives = 0;
    } else if (own_guess->result == RESULT_MEDIUM_BOAT_SUNK) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
        opp_field->largeBoatLives = 0;
    } else if (own_guess->result == RESULT_SMALL_BOAT_SUNK) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
        opp_field->hugeBoatLives = 0;
    }
    return y;
}

uint8_t FieldGetBoatStates(const Field *f) {
    uint8_t z = 0; 
    if (f->hugeBoatLives > 0) {
        z = z | FIELD_BOAT_STATUS_HUGE;
    } else if (f->largeBoatLives > 0) {
        z = z | FIELD_BOAT_STATUS_LARGE;
    } else if (f->mediumBoatLives > 0) {
        z = z | FIELD_BOAT_STATUS_MEDIUM;
    } else if (f->smallBoatLives > 0) {
        z = z | FIELD_BOAT_STATUS_SMALL;
    }
    return z;
}


int randomNumber(int min, int max) {
    int r;
    r = (rand() % (max - min + 1)) + min; 
    return r;
}

uint8_t FieldAIPlaceAllBoats(Field *own_field) {

    uint8_t t;
    
    while (1) {
        int a = rand() % FIELD_ROWS;
        int b = rand() % FIELD_COLS;
        
        t = FieldAddBoat(own_field, a, b, FIELD_DIR_SOUTH, FIELD_BOAT_TYPE_HUGE);
        if (t == SUCCESS){
            break;
        }
    }
    t = 0;
    while (1) {
        int a = rand() % FIELD_ROWS;
        int b = rand() % FIELD_COLS;
        
        t = FieldAddBoat(own_field, a, b, FIELD_DIR_EAST, FIELD_BOAT_TYPE_LARGE);
        if (t == SUCCESS){
            break;
        }
    }
    t = 0;
    while (1) {
        int a = rand() % FIELD_ROWS;
        int b = rand() % FIELD_COLS;
        
        t = FieldAddBoat(own_field, a, b, FIELD_DIR_SOUTH, FIELD_BOAT_TYPE_MEDIUM);
        if (t == SUCCESS){
            break;
        }
    }
    t = 0;
    while (1) {
        int a = rand() % FIELD_ROWS;
        int b = rand() % FIELD_COLS;
        
        t = FieldAddBoat(own_field, a, b, FIELD_DIR_EAST, FIELD_BOAT_TYPE_SMALL);
        if (t == SUCCESS){
            break;
        }
    }
    t = 0;
    
    return SUCCESS;
}

GuessData FieldAIDecideGuess(const Field *opp_field) {
    GuessData guess;
    
    while (1) {
        int a = randomNumber(0, FIELD_ROWS-1);
        int b = randomNumber(0, FIELD_COLS-1);
        
        if (opp_field->grid[a][b] == FIELD_SQUARE_UNKNOWN) {
            guess.row = a;
            guess.col = b;
            return guess;       
        }
    }
}
