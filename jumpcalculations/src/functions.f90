module mainfunctions
    implicit none
    ! How to use functions
    ! Read: https://pages.mtu.edu/~shene/COURSES/cs201/NOTES/F90-Subprograms.pdf

contains
    real function calculateheight(u) result(res) 
        implicit none
        real, intent (in) :: u
        real :: g = 9.8

        res = u**1/2*g
    end function calculateheight

    real function timetoreachheight(u) result(res)
        implicit none
        real, intent (in) :: u
        real :: g = 9.8

        res = u/g
    end function timetoreachheight

    real function timetoland(hmax) result(res)
        implicit none
        real, intent (in) :: hmax
        real :: g = 9.8

        res = SQRT(2*hmax/g)
    end function timetoland

end module mainfunctions
