## php-allegro-primitives

PHP bindings to the [allegro 5](https://liballeg.org/) C library.

**Requirements**
* PHP >= 8.1
* PHP FFI extension available
* allegro 5

**Example:**

```php
<?php

require __DIR__ . '/vendor/autoload.php';

use AllegroPHP\Allegro\Allegro;
use AllegroPHP\Primitives\Primitives;
use AllegroPHP\Allegro\Event\Type;

$allegro = new Allegro();
$primitives = new Primitives();

$init = $allegro->al_install_system($allegro->al_get_allegro_version(), function (){});

$display = $allegro->al_create_display(500, 500);
$queue = $allegro->al_create_event_queue();
$timer = $allegro->al_create_timer(1.0 / 60);

$event_queue = $allegro->al_create_event_queue();

$allegro->al_install_keyboard();

$allegro->al_register_event_source($event_queue, $allegro->al_get_keyboard_event_source());
$allegro->al_register_event_source($event_queue, $allegro->al_get_display_event_source($display));
$allegro->al_register_event_source($event_queue, $allegro->al_get_timer_event_source($timer));
$primitives->al_init_primitives_addon();
$color = $primitives->cast('ALLEGRO_COLOR', $allegro->al_map_rgb(255, 0, 0));
$event = $allegro->new('ALLEGRO_EVENT');
$transform = $allegro->new('ALLEGRO_TRANSFORM');
$allegro->al_identity_transform(FFI::addr($transform));
$allegro->al_translate_transform(FFI::addr($transform), 100, 100);
$allegro->al_use_transform(FFI::addr($transform));
$primitives->al_draw_line(-8, 9, 0, -11, $color, 3.0);
$primitives->al_draw_line(0, -11, 8, 9, $color, 3.0);
$primitives->al_draw_line(-6, 4, -1, 4, $color, 3.0);
$primitives->al_draw_line(6, 4, 1, 4, $color, 3.0);
$allegro->al_flip_display();
$running = true;
while ($running){

    $allegro->al_wait_for_event($event_queue, FFI::addr($event));

    if ($event->type === Type::DISPLAY_CLOSE) {
        $running = false;
    }
}

$allegro->al_destroy_display($display);
```
