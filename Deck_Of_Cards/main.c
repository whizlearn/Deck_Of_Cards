/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Nicholas Dass
 *
 * Created on October 26th, 2016, 1:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  card_t{
    
 char face[10];
 char suit[10];
 
};

// This method fills the deck with each suit and the face values for each suit.
void fill_deck(struct card_t* deck){
    char *suits[4]={"CLUBS","DIAMONDS","HEARTS","SPADES"};
    char *faces[13]={"2", "3", "4", "5", "6", "7", "8", "9", "10", "JACK", "QUEEN", "KING", "ACE"};
    
    for(int i = 0; i < 13; i++){
        
        for(int e = 0; e < 4; e++){
            //reference a spot in the deck with deck[0]
            strcpy(deck[i*4+e].suit, suits[e]);
            strcpy(deck[i*4+e].face, faces[i]);
        }        
    }
}

// This method prints the deck of cards 
void print_deck(struct card_t* deck){
    
    for(int i = 0; i < 13; i++){
        for(int e=0;e<4;e++){
            printf("%s of %s\t", deck[i*4+e].face, deck[i*4+e].suit);
        }
        printf("\n");
    }
    printf("\n\n");
}

// This method shuffles the deck of cards.
void shuffle_deck(struct card_t* deck){
    struct card_t a;
    int j;
    
    for(int i = 0; i < 52; i++){
        
        a = deck[i];
        
        j = rand() % 52;       
        deck[i]=deck[j];
        
        deck[j]=a;
        
    }
}

int main(int argc, char** argv) {
    
    struct card_t* deck[52];
    fill_deck(deck);
    print_deck(deck);
    shuffle_deck(deck);
    print_deck(deck);
    
}