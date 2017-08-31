#!/usr/local/bin/perl

for ( $i = 3750; $i < 4000; $i++ )
{
    print $i;
    print " ";
    $command = "ddump -p 910 -t 9 JinData/beam/beam_0000$i-0000.prdf | grep \'E:2CH\' | awk \'{print \$3}\' ";
    $h = `$command`;
    chomp($h);
    if ( !$h ) { $h = -9; }
    print $h;
    print " ";
    $command = "ddump -p 910 -t 9 JinData/beam/beam_0000$i-0000.prdf | grep \'E:2CV\' | awk \'{print \$3}\' ";
    $h = `$command`;
    chomp($h);
    if ( !$h ) { $h = -9; }
    print $h;
    print "\n";
}

