<?php

namespace AllegroPHP\Primitives;

use Serafim\FFILoader\BitDepth;
use Serafim\FFILoader\Library as BaseLibrary;
use Serafim\FFILoader\OperatingSystem;

class Library extends BaseLibrary
{
    private const LIBRARY_LINUX = 'liballegro_primitives.so';

    private ?string $version = '0.1.0';

    public function getName(): string
    {
        return 'allegro_primitives';
    }

    public function getVersion(string $library): string
    {
        return $this->version;
    }

    public function getHeaders(): string
    {
        return __DIR__ . '/../resources/primitives.h';
    }

    /**
     * {@inheritDoc}
     */
    public function getOutputDirectory(): string
    {
        return __DIR__ . '/../out';
    }

    public function getLibrary(OperatingSystem $os, BitDepth $bits): ?string
    {
        switch (true) {
            case $os->isLinux():
                return self::LIBRARY_LINUX;
            default:
                return null;
        }
    }
}