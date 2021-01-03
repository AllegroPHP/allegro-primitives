<?php

declare(strict_types=1);

namespace AllegroPHP\Primitives;

use Serafim\FFILoader\LibraryInformation;
use Serafim\FFILoader\LibraryInterface;
use Serafim\FFILoader\Loader;

class Primitives
{
    public function __construct()
    {
        $this->loader = $this->loader();

        $this->info = $this->loadLibrary(new Library());

        self::setInstance($this);
    }

    /**
     * @return Loader
     */
    private function loader(): Loader
    {
        $loader = new Loader();

        $pre = $loader->preprocessor();
        $pre->keepComments = false;
        $pre->minify = false;
        $pre->tolerant = false;

        return $loader;
    }

    /**
     * @var self|null
     */
    private static ?self $instance = null;

    /**
     * @return static
     */
    public static function getInstance(): self
    {
        return self::$instance ??= new static();
    }

    /**
     * @param Primitives|null $instance
     */
    public static function setInstance(?self $instance): void
    {
        self::$instance = $instance;
    }

    /**
     * @param LibraryInterface $library
     *
     * @return LibraryInformation
     */
    public function loadLibrary(LibraryInterface $library): LibraryInformation
    {
        return $this->loader->load($library);
    }
}