#include <stdio.h>

int inAlphabet(char letter, char* alphabet, int alphabetSize){
    int result = 0;
    for(int i = 0; i < alphabetSize; i++){
        if(letter == *(alphabet+i)){
            result = 1;
            break;
        }
    }

    return result;
}

int isFinal(int state, int* finalStates, int finalStatesSize){
    int result = 0;
    for(int i = 0; i < finalStatesSize; i++){
        if(state == *(finalStates+i)){
            result = 1;
            break;
        }
    }

    return result;
}

int tryWord(char* word){
    //automata initialization
    char alphabet[] = {'a', 'b'};
    int alphabetSize = sizeof(alphabet);
    enum states
    {start, a, aa, aaa, aaaa, aaaaa,
        b, bb, bbb, bbbb, bbbbb, sink,
        a2b, a3b, a3b2, a4b, a4b2, a4b3,
        a5b, a5b2, a5b3, a5b4};
    int curr_state = start;
    int final_states[] = {
            start, a, aa, aaa, aaaa, aaaaa,
            b, bb, bbb, bbbb, bbbbb,
            a2b, a3b, a3b2, a4b, a4b2, a4b3,
            a5b, a5b2, a5b3, a5b4};
    int finalStatesSize = sizeof(final_states)/sizeof(int);
    char curr_char;
    int result = 0;

    //START
    do{
        scanf("%c", &curr_char);
        if(!(inAlphabet(curr_char, alphabet, alphabetSize)) && curr_char != '\0'){
            printf("%c", curr_char);
            printf("Sorry, this string doesn't belong to the alphabet.");
            result = 0;
            break;
        } else {
            //transition function
            switch(curr_state){
                case start:
                    if(curr_char == 'a'){
                        curr_state = a;
                    } else {
                        curr_state = b;
                    }
                    break;
                case a:
                    if(curr_char == 'a'){
                        curr_state = aa;
                    } else {
                        curr_state = b;
                    }
                    break;
                case aa:
                    if(curr_char == 'a'){
                        curr_state = aaa;
                    } else {
                        curr_state = a2b;
                    }
                    break;
                case aaa:
                    if(curr_char == 'a'){
                        curr_state = aaaa;
                    } else {
                        curr_state = a3b;
                    }
                    break;
                case aaaa:
                    if(curr_char == 'a'){
                        curr_state = aaaaa;
                    } else {
                        curr_state = a4b;
                    }
                    break;
                case aaaaa:
                    if(curr_char == 'a'){
                        curr_state = sink;
                    } else {
                        curr_state = a5b;
                    }
                    break;
                case b:
                    if(curr_char == 'a'){
                        curr_state = a;
                    } else {
                        curr_state = bb;
                    }
                    break;
                case bb:
                    if(curr_char == 'a'){
                        curr_state = a2b;
                    } else {
                        curr_state = bbb;
                    }
                    break;
                case bbb:
                    if(curr_char == 'a'){
                        curr_state = a3b2;
                    } else {
                        curr_state = bbbb;
                    }
                    break;
                case bbbb:
                    if(curr_char == 'a'){
                        curr_state = a4b3;
                    } else {
                        curr_state = bbbbb;
                    }
                    break;
                case bbbbb:
                    if(curr_char == 'a'){
                        curr_state = a5b4;
                    } else {
                        curr_state = sink;
                    }
                    break;
                case sink:
                    if(curr_char == 'a'){
                        curr_state = sink;
                    } else {
                        curr_state = sink;
                    }
                    break;
                case a2b:
                    if(curr_char == 'a'){
                        curr_state = aa;
                    } else {
                        curr_state = bb;
                    }
                    break;
                case a3b:
                    if(curr_char == 'a'){
                        curr_state = aaa;
                    } else {
                        curr_state = a3b2;
                    }
                    break;
                case a3b2:
                    if(curr_char == 'a'){
                        curr_state = a3b;
                    } else {
                        curr_state = bbb;
                    }
                    break;
                case a4b:
                    if(curr_char == 'a'){
                        curr_state = aaaa;
                    } else {
                        curr_state = a4b2;
                    }
                    break;
                case a4b2:
                    if(curr_char == 'a'){
                        curr_state = a4b;
                    } else {
                        curr_state = a4b3;
                    }
                    break;
                case a4b3:
                    if(curr_char == 'a'){
                        curr_state = a4b2;
                    } else {
                        curr_state = bbbb;
                    }
                    break;
                case a5b:
                    if(curr_char == 'a'){
                        curr_state = aaaaa;
                    } else {
                        curr_state = a5b2;
                    }
                    break;
                case a5b2:
                    if(curr_char == 'a'){
                        curr_state = a5b;
                    } else {
                        curr_state = a5b3;
                    }
                    break;
                case a5b3:
                    if(curr_char == 'a'){
                        curr_state = a5b2;
                    } else {
                        curr_state = a5b4;
                    }
                    break;
                case a5b4:
                    if(curr_char == 'a'){
                        curr_state = a5b3;
                    } else {
                        curr_state = bbbbb;
                    }
                    break;
            }
        }

    } while(curr_char != '\0');
    if(isFinal(curr_state, final_states, finalStatesSize)){
        result = 1;
    } else {
        result = 0;
    }

    return result
}

int main() {

    return 0;
}
