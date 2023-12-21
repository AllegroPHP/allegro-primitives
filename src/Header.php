<?php

namespace AllegroPHP\Primitives;

use FFI\Contracts\Headers\HeaderInterface;
use FFI\Contracts\Preprocessor\PreprocessorInterface;

final class Header implements HeaderInterface
{
    private const HEADERS_ENTRYPOINT = __DIR__ . '/../resources/primitives.h';

    public function __construct(
        private readonly PreprocessorInterface $pre,
    ) {
    }

    public function getPathname(): string
    {
        return self::HEADERS_ENTRYPOINT;
    }

    public function __toString(): string
    {
        return (string)$this->pre->process(new \SplFileInfo($this->getPathname()));
    }
}
