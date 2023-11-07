        PROGRAM pgm1
        IMPLICIT NONE
        INTEGER :: input, sixth, fifth, third, first
        write(*,*) "What number did prison ex give you?"
        read(*,*) input
        
        sixth = mod(input,10)
        fifth = mod(input/10, 10)
        third = mod(input/1000, 10)
        first = mod(input/100000, 10)
        write(*,*) "Use", sixth, fifth, third, first

        END PROGRAM

