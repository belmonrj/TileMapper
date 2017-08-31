#!/usr/local/bin/perl

for ( $i = 3750; $i < 3900; $i++ )
{
    print $i;
    print " ";
    #$command = "ddump -p 910 -t 9 JinData/beam/beam_0000$i-0000.prdf";
    #print "command is $command \n";
    #$h = `$command`;
    #system(
    #system("ddump -p 910 -t 9 Data/beam/beam_0000$i-0000.prdf | grep 'E:2CH' | awk '{print $3}'");
    #$h = `ddump -p 910 -t 9 Data/beam/beam_0000%d-0000.prdf | grep 'E:2CH' | awk '{print $3}'`;
    #print "Here's the variable ";
    #print "\n";
    $command = "ddump -p 910 -t 9 JinData/beam/beam_0000$i-0000.prdf | grep \'E:2CH\' | awk \'{print \$3}\' ";
    #print "command is $command \n";
    $h = `$command`;
    chomp($h);
    print $h;
    print " ";
    $command = "ddump -p 910 -t 9 JinData/beam/beam_0000$i-0000.prdf | grep \'E:2CV\' | awk \'{print \$3}\' ";
    #print "command is $command \n";
    $h = `$command`;
    chomp($h);
    print $h;
    print "\n";
}

