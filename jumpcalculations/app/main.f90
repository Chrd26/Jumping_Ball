program main
    use mainfunctions
    ! import csv_module from here: https://github.com/jacobwilliams/csv-fortran
    use csv_module
    use iso_fortran_env, only: wp => real64
    implicit none

    character(100) :: inputvalue
    real :: tmaximumheight, tland, initialvelocity, maxheight
    logical :: status_ok
    type(csv_file) :: f

    ! Make sure that there are arguments
    ! To run with fpm and cmd args, fpm run -- value
    if (command_argument_count().ne.1) then
        write(*,*) "Error, 1 argument is required!"
        stop
    end if

    ! Get the value from input
    call get_command_argument(1, inputvalue)
    
    ! convert to integer
    read(inputvalue, *)initialvelocity

    ! set verbosity
    call f%initialize(verbose = .true.)

    ! Open csv file
    call f%open("./app/output/calculations.csv", n_cols = 4, status_ok = status_ok)

    maxheight = calculateheight(initialvelocity)
    tmaximumheight = timetoreachheight(initialvelocity)
    tland = timetoland(maxheight)

    !print *, maxheight
    !print *, tmaximumheight
    !print *, tland

    ! Add headers and move pointer to the next row
    call f%add(["a", "b", "c", "t"])
    call f%next_row()

    ! Add data to the csv file
    call f%add([maxheight, tmaximumheight, tland], real_fmt='(F5.1)')
    call f%add(.true.)

    ! Close
    call f%close(status_ok)

end program main
