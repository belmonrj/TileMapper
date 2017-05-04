#!/usr/local/bin/perl

for ( $i = 3750; $i < 3751; $i++ )
{
    $command = "ddump -p 910 -t 9 Data/beam/beam_0000$i-0000.prdf";
    print "command is $command \n";
    $h = `$command`;
    #system(
    #system("ddump -p 910 -t 9 Data/beam/beam_0000$i-0000.prdf | grep 'E:2CH' | awk '{print $3}'");
    #$h = `ddump -p 910 -t 9 Data/beam/beam_0000%d-0000.prdf | grep 'E:2CH' | awk '{print $3}'`;
    #print "Here's the variable ";
    print $h;
    #print "\n";
}

