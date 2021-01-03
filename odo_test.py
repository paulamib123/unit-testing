from odometer import Odometer

o1 = Odometer(5)
o2 = Odometer(2)

def testLength():
    length1 = o1.LENGTH
    length2 = o2.LENGTH
    assert length1 == 126
    assert length2 == 36

def testNextReading():
    o1.next_reading(10)
    assert o1.readings[o1.position] == 12368

    o2.next_reading(4)
    assert o2.readings[o2.position] == 16

def textPrevReading():
    o1.prev_reading(6)
    assert o1.readings[o1.position] == 14

    o2.prev_reading(2)
    assert o2.readings[o2.position] == 12349

def testDiff():
    o3 = Odometer(3)
    o4 = Odometer(3)
    o3.next_reading(4)
    o3.prev_reading(6)
    assert o3.diff(o4) == 2
    assert o4.diff(o3) == 82



