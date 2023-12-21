<?php

declare(strict_types=1);

namespace AllegroPHP\Primitives;

use FFI\Contracts\Preprocessor\PreprocessorInterface;
use FFI\Location\Locator;
use FFI\Preprocessor\Preprocessor;
use FFI\Proxy\Proxy;
use Psr\SimpleCache\CacheInterface;

class Primitives extends Proxy
{
    private readonly string $library;

    public function __construct(
        ?string               $library = null,
        CacheInterface        $cache = null,
        PreprocessorInterface $pre = new Preprocessor(),
    )
    {
        $this->library = $this->detectLibraryPathname($library);
        $header = $this->getHeader($pre, $cache);
        parent::__construct(\FFI::cdef((string)$header, $this->library));
    }

    private function getHeader(PreprocessorInterface $pre, ?CacheInterface $cache): string|\Stringable
    {
//        if ($cache !== null) {
//        }

        return new Header($pre);
    }

    private function detectLibraryPathname(?string $library): string
    {
        if ($library !== null) {
            return \realpath($library) ?: Locator::resolve($library) ?? $library;
        }

        return match (\PHP_OS_FAMILY) {
            'Windows' => Locator::resolve('liballegro_primitives.dll')
                ?? throw new \RuntimeException(<<<'error'
                    Could not load [liballegro_primitives.dll].
                    error
                ),
            'BSD',
            'Linux' => Locator::resolve('liballegro_primitives.so')
                ?? throw new \RuntimeException(<<<'error'
                    Could not load [liballegro_primitives.so].
                    error
                ),
            'Darwin' => Locator::resolve('liballegro_primitives.dylib')
                ?? throw new \RuntimeException(<<<'error'
                    Could not load [liballegro_primitives.dylib].
                    error
                ),
        };
    }
}
